
class BrowserHistory {
	//we are creating a vector of strings to store the url string 
    vector<string>list;
	//idx will show on which index of vector are we on
    int idx=-1;
	//the maxSize is used to store the maximum size of the vector 
		//it contain size of the possible vector 
    int maxSize=0;
public:
//In BrowserHistory we will simply initialize our vector and idx to 0 and maxSize to one
    BrowserHistory(string homepage) {
        list.push_back(homepage);
        
        idx=0;
        maxSize=1;
    }
    //when we are visiting a url we can have two options
		//1. if we are not on the end of list.size() i.e. idx<list.size()-1
			//then we will simply put the url at next index and increase idx and also update maxSize to idx+1
		//2. else we are on the end of vector we will have to push back to the vector and the both idx and maxSize increase by one
    void visit(string url) {
	//First condition
        if(list.size()-1>idx){
            list[idx+1]=url;
            
            idx++;
            maxSize=idx+1;
        }
		//2nd condition
        else{
            list.push_back(url);
            
            idx++;
            maxSize++;
        }
    }
    
    string back(int steps) {
		//we will find the val to which we can go back
        int val=min(steps,idx);
		//substract from the idx
        
        idx-=val;
		//return the list[idx]
        return list[idx];
    }
    
    string forward(int steps) {
		//we will find the val to which we can go back
        int val=min(steps,maxSize-idx-1);
		//add from the idx
        idx+=val;
		//return the list[idx]
        return list[idx];
    }
};