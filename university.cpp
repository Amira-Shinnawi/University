#include "iostream"
#include "vector"
using namespace std;
class Department
{
private:
    string name;
    int capacity;
    int requiredGPA;

public:
    Department()
    {
        cout << "Department default constructor" << endl;
    }
    Department(string name, int capacity, int requiredGPA)
    {
        this->name = name;
        this->capacity = capacity;
        this->requiredGPA = requiredGPA;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }

    void setCapacity(int capacity)
    {
        this->capacity = capacity;
    }
    int getCapacity()
    {
        return this->capacity;
    }

    void setRequiredGPA(int requiredGPA)
    {
        this->requiredGPA;
    }
    int getRequiredGPA()
    {
        return this->requiredGPA;
    }
    ~Department(){}
};

class Person
{
private:
    int id;
    string name;
    char gender;
    int age;

public:
Person(int id, string name,int age,char gender){
this->id = id;
this->name = name;
this->age = age;
this->gender = gender;

}
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }

    void setGender(char gender)
    {
        this->gender = gender;
    }
    char getGender()
    {
        return this->gender;
    }

    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return this->age;
    }
};

class Student : public Person
{
private:

    int level;
    float gpa;

public:
    Student(int id,string name ,int age,char gender,int level, float gpa):Person(id,name,age,gender)
    {
       
        this->level = level;
        this->gpa = gpa;
       
    }
    void setLevel(int level)
    {
        this->level = level;
    }
    int getLevel()
    {
        return this->level;
    }
    void setGpa(float gpa)
    {
        this->gpa = gpa;
    }
    float getGpa()
    {
        return this->gpa;
    }
    ~Student(){

    }
};

class Professor : public Person
{
private:
    int salary;
    string degree;
    Department* department;
public:

    Professor(int id,string name,int age, char gender,Department *department,int salary, string degree):
        Person(id,name,age,gender)
    {
        
        this->salary = salary;
        this->degree = degree;
        this->department = department;


    }
    void setSalary(int s)
    {
        this->salary = s;
    }
    int getSalary()
    {
        return salary;
    }

    void setDepartment(Department * department)
    {
        this->department = department;
    }
    Department* getDepartment()
    {
        return this->department;
    }

    void setDegree(string degree)
    {
        this->degree = degree;
    }
    string getDegree()
    {
        return degree;
    }
    ~Professor(){}
};

class Course
{
private:
    string courseName;
    int courseHours;
    string courseCode;
    Professor* professor;
    vector<Course*> prerequisites;
    vector<Student*> students;
public:
    Course()
    {
        cout << "Course default constructor" << endl;
    }

    Course(string courseName, string courseCode,int courseHours,vector<Course*>preCourse,Professor* professor,vector<Student*>student)
    {
        this->courseName = courseName;
        this->courseHours = courseHours;
        this->courseCode = courseCode;
        this->professor = professor;
    }
    void setCourseName(string courseName)
    {
        this->courseName = courseName;
    }
    void setCourseCode(string courseCode)
    {
        this->courseCode = courseCode;
    }
    void setCourseHours(int courseHours)
    {
        this->courseHours = courseHours;
    }
    void setProfessor(Professor* professor)
    {
        this->professor = professor;
    }

    string getCoursename()
    {
        return this->courseName;
    }
    int getCourseHours()
    {
        return this->courseHours;
    }
    string getCourseCode()
    {
        return this->courseCode;
    }
    Professor* getProffesor()
    {
        return this->professor;
    }
    ~Course(){
    }
};

class University
{
private:
    static University *instancePtr;
    vector<Student> students;
    vector<Department> departments;
    vector<Professor> professors;
    vector<Course> courses;
    University() {}

public:
    University(const University &obj) = delete;
    static University *getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new University();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }
    ///////////////////////////////////COURSE//////////////////////////////////////////////////////////
    void addCourses(string courseName, string courseCode,int courseHours,vector<Course*>prerequiestis,Professor*prof,vector<Student*>stu)
    {
        Course course(courseName, courseCode,courseHours,prerequiestis,prof,stu);
        courses.push_back(course);
    }
    void PrintCourses()
    {
        if (courses.empty())
        {
            cout << "No Courses Yet" << endl;
        }
        else
        {
            for (int i = 0; i < courses.size(); i++)
            {
                cout << "Course Name: " << courses[i].getCoursename() << " Course Hours: " << courses[i].getCourseHours() << " Course COde: " << courses[i].getCourseCode() << " Professor Course: " << courses[i].getProffesor() << endl;
            }
        }
    }
    void updateCourse(int index, int newcourseHour)
    {
        if (index >= 0 && index < courses.size())
        {
            courses[index].setCourseHours(newcourseHour);

            cout << "Course Hour" << index << " edited" << endl;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }
    void SearchCourse(string coursecode)
    {
         for (int i = 0; i < courses.size(); i++)
        {
            if (coursecode == departments[i].getName())
            {
                cout << "Course Name : " << courses[i].getCoursename() << endl;
                cout << "Course Hour: " << courses[i].getCourseHours() << endl;
                cout << "Course Code: " << courses[i].getCourseCode() << endl;
                cout << "Professor Course:: " << courses[i].getProffesor() << endl;
            }
            else
            {
                cout << "Course Not Found: " << endl;
            }
        }
    }
    void deleteCourse(int index)
    {
        if (index >= 0 && index < courses.size())
        {
            courses.erase(courses.begin() + index);
            cout << "Course deleted successfully!" << endl;
        }
        else
        {
            cout << "Invalid index." << endl;
        }
    }
    ////////////////////////////////PROFESSOR////////////////////////////////////////////////////
    void addProfessors(int id, string name,int age,char gender,Department*depa,int salary, string degree)
    {
        Professor professor(id,name,age,gender,depa,salary,degree);
        professors.push_back(professor);
    }
    void printProfessor()
    {
        if (professors.empty())
        {
            cout << "No Professor" << endl;
        }
        else
        {
            for (int i = 0; i < professors.size(); i++)
            {
                cout << "Professor ID: " << professors[i].getId() << " Professor Salary: " << professors[i].getSalary() << " Professor Department: " << professors[i].getDepartment()<< " Professor: " << professors[i].getDegree() <<"Professor Name: "<<professors[i].getName()<<"Professor Gender: "<<professors[i].getGender()<<" Professor Age: "<<professors[i].getAge()<< endl;
            }
        }
    }
    void updateProfessor(int index, int newSalary)
    {
        if (index >= 0 && index < professors.size())
        {
            professors[index].setSalary(newSalary);

            cout << "Professor Salary" << index << " edited" << endl;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }
    void SearchProfessor(int id)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (id == professors[i].getId())
            {
                cout << "Professor ID : " << professors[i].getId() << endl;
                cout << "Professor Salary: " << professors[i].getSalary() << endl;
                cout << "Professor Department: " << professors[i].getDepartment() << endl;
                cout << "Professor Degree: " << professors[i].getDegree() << endl;
                cout << "Professor Name: " << professors[i].getName() << endl;
                cout << "Professor Gender: " << professors[i].getGender() << endl;
                cout << "Professor Age: " << professors[i].getAge() << endl;


            }
            else
            {
                cout << "Profeesor Not Found: " << endl;
            }
        }
    }
    void deleteProfessor(int index)
    {
        if (index >= 0 && index < professors.size())
        {
            professors.erase(professors.begin() + index);
            cout << "Professor deleted successfully!" << endl;
        }
        else
        {
            cout << "Invalid index." << endl;
        }
    }
    ////////////////////////////DEPARTMENT//////////////////////////////////////////////
    void addDepartment(string name, int capacity, int requiredGPA)
    {
        Department department(name, capacity, requiredGPA);
        departments.push_back(department);
    }
    void printDepartment()
    {
        if (departments.empty())
        {
            cout << "No Department" << endl;
        }
        else
        {
            for (int i = 0; i < departments.size(); i++)
            {
                cout << "Department Name: " << departments[i].getName() << " Capacity: " << departments[i].getCapacity() << " Required GPA: " << departments[i].getRequiredGPA() << endl;
            }
        }
    }
    void updateDepartment(int index, int newrequiredGPA)
    {
        if (index >= 0 && index < departments.size())
        {
            departments[index].setRequiredGPA(newrequiredGPA);

            cout << "Department at index " << index << " edited" << endl;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }
    void SearchDepartment(string name)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (name == departments[i].getName())
            {
                cout << "Department Name: " << departments[i].getName() << endl;
                cout << "Department Capacity: " << departments[i].getCapacity() << endl;
                cout << "Dpartment RequiredGPA: " << departments[i].getRequiredGPA() << endl;
            }
            else
            {
                cout << "Department Not Found: " << endl;
            }
        }
    }
    void deleteDepartment(int index)
    {
        if (index >= 0 && index < departments.size())
        {
            departments.erase(departments.begin() + index);
            cout << "Department deleted successfully!" << endl;
        }
        else
        {
            cout << "Invalid index." << endl;
        }
    }
    ////////////////////////STUDENT//////////////////////////////////////////
    void addStudent(int id ,string name,int age,char gender,int level, float gpa )
    {
        Student student(id,name,age,gender,level,gpa);
        students.push_back(student);
    }
    void printStudents()
    {
        if (students.empty())
        {
            cout << "No students" << endl;
        }
        else
        {
            for (int i = 0; i < students.size(); i++)
            {
                cout << "ID: " << students[i].getId() << " Level: " << students[i].getLevel() << " GPA: " << students[i].getGpa() << "Student Name: "<<students[i].getName()<<"Student Gender: "<<students[i].getGender()<<"Student Age: "<<students[i].getAge()<< endl;
            }
        }
    }
    void updateStudent(int index, float newGPA)
    {
        if (index >= 0 && index < students.size())
        {
            students[index].setGpa(newGPA);

            cout << "Student at index " << index << " edited" << endl;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }
    void SearchStudent(int id)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (id == students[i].getId())
            {
                cout << "Student ID: " << students[i].getId() << endl;
                cout << "Student Level: " << students[i].getLevel() << endl;
                cout << "Student GPA: " << students[i].getGpa() << endl;
                 cout << "Student Name: " << students[i].getName() << endl;
                  cout << "Student Gender: " << students[i].getGender() << endl;\
                   cout << "Student Age: " << students[i].getAge() << endl;
            }
            else
            {
                cout << "Student Not Found: " << endl;
            }
        }
    }
    void deleteStudent(int index)
    {
        if (index >= 0 && index < students.size())
        {
            students.erase(students.begin() + index);
            cout << "Student deleted successfully!" << endl;
        }
        else
        {
            cout << "Invalid index." << endl;
        }
    }
    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1,"Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);
        Student s2(2,"Mirna Hussein", 22, 'F', 4, 3.68);
        students.push_back(s2);
        Student s3(3,"Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4,"Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(s4);
        Student s5(5,"Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(s5);
        Student s6(6,"Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7,"Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8,"Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

       Professor p1(1,"Mohamed Ali", 56, 'M', &d1, 12000, "Masters");
        professors.push_back(p1);
        Professor p2(2,"Ehsan Ahmed", 43, 'M', &d2, 8500, "Masters");
        professors.push_back(p2);
        Professor p3(3,"Ahmed Mohsen", 68, 'M', &d3, 19380, "Masters");
        professors.push_back(p3);
        Professor p4(4,"Abdelhady", 61, 'M', &d4, 22728, "Masters");
        professors.push_back(p4);
        Professor p5(5,"Taghreed Mohsen", 49, 'F', &d2, 11068, "Masters");
        professors.push_back(p5);



        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1,&p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for(int i=0; i<departments.size(); i++)
        {
            cout<<"Department: "<<departments[i].getName()<<endl;
        }
        for(int i=0; i<professors.size(); i++)
        {
            cout<<"Professor Name: "<<professors[i].getName()<<endl;
        }
        for(int i=0; i<students.size(); i++)
        {
            cout<<"Student Name: "<<students[i].getName()<<endl;
        }
        for(int i=0; i<courses.size(); i++)
        {
            cout<<"Course Name: "<<courses[i].getCoursename()<<endl;
        }
    }
    ~University(){}
};
University *University::instancePtr = NULL;

int main(){
    University *uni = University::getInstance();
   
    return 0;
}
