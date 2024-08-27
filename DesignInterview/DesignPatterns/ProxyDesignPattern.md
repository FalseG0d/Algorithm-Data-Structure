# Design Pattern

Proxy is an object placed between 2 object to help them communicate. This help can be in the form of.

1. Block illegal actions
2. Caching
3. Pre and Post Processing a request


interface EmployeeSchema {
    void create();
    void edit();
    void delete();
}

class EmployeeDao implements EmployeeSchema {
    void create(){
        System.out.println("create");
    }
    void edit(){
        System.out.println("edit");
    }
    void delete(){
        System.out.println("delete");
    }
}

class EmployeeDaoProxy implements EmployeeSchema {
    EmployeeDao employeeDaoObj;

    void create(User user){
        if(user.isAdmin())
            employeeDaoObvj.create();
    }
    void edit(User user){
        if(user.isDesigner())
            employeeDaoObvj.edit();
    }
    void delete(User user){
        if(user.isAdmin())
            employeeDaoObvj.delete();
    }
}