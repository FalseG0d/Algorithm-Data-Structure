# Builder Design Pattern


If the class has a lot of class variables then we will have to create a very large Constructor parameter list, which might not be available so instead we will have to send in NULL for many of them. So instead what we can do is the following.


We can have a number of functions to set the various class variables and then return this itself. Finally create a build function which will return a new variable by using a Copy Constructor.


class Student {
    int age;
    int rollNo;
    String name;
    String fatherName;

    Student(StudentBuilder sb) {
        this.age = s.age;
        this.rollNo = s.rollNo;
        this.name = s.name;
        this.fatherName = s.fatherName;
    }
}

class StudentBuilder {
    int age;
    int rollNo;
    String name;
    String fatherName;

    StudentBuilder(StudentBuilder sb) {
        
    }

    StudentBuilder setAge(int age) {
        this.age = age;
        return this;
    }

    StudentBuilder setRollNo(int rollNo) {
        this.rollNo = rollNo;
        return this;
    }

    StudentBuilder setName(String name) {
        this.name = name;
        return this;
    }

    StudentBuilder setFatherName(int fatherName) {
        this.fatherName = fatherName;
        return this;
    }

    Student build() {
        return new Student(this);
    }
}