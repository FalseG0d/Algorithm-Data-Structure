from flask import Flask,render_template,request,redirect,url_for
from modules.database import mongo
from decouple import config

app=Flask(__name__)
app.config["MONGO_URI"]=config('MONGO_URI')
mongo.init_app(app)

app.secret_key=config('SECRET_KEY')

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/add",methods=['POST'])
def add():
    name=request.form['name']
    description=request.form['description']
    image=request.files['image']
    key=float(request.form['key'])

    fashion_collection=mongo.db.fashion

    mongo.save_file(image.filename,image)
    fashion_collection.insert_one({
        'name':name,
        'description':description,
        'image':image.filename,
        'key':key,
    })

    return redirect(url_for('home'))

@app.route("/view")
def view():
    fashion_collection=mongo.db.fashion
    items=fashion_collection.find()

    return render_template("list.html",items=items)

@app.route('/file/<filename>')
def file(filename):
    return mongo.send_file(filename)

def main():
    app.run(debug=True)

if __name__=='__main__':
    main()