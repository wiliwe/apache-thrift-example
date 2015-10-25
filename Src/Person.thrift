namespace cpp IDV
namespace php IDV
namespace java IDV

struct Person{
    1:i32 id;
    2:string name;
    3:i32 age;
    4:bool married;
}

service PersonService{
    Person getPersonById(1:i32 id),
    bool deletePersonById(1:i32 id)
}
