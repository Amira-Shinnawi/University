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
};
class Person
{
private:
    int id;
    string name;
    char gender;
    int age;

public:
    void setId(int i)
    {
        this->id = i;
    }
    int getId()
    {
        return id;
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }

    void setGender(char gender)
    {
        this->gender = gender;
    }
    char getGender()
    {
        return gender;
    }

    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }
};
class Student : public Person
{
private:

    int level;
    float gpa;

public:
    Student()
    {
        cout << "Student default constructor" << endl;
    }
    Student(int id, int level, float gpa)
    {
        setId(id);
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
};
class Professor : public Person
{
private:
    int id;
    int salary;
    string department;
    string degree;

public:
    Professor()
    {
        cout << "Professor default constructor" << endl;
    }
    Professor(int id, int salary, string department, string degree)
    {
        setId(id);
        this->salary = salary;
        this->department = department;
        this->degree = degree;
    }
    void setId(int i)
    {
        this->id = i;
    }
    int getId()
    {
        return id;
    }
    void setSalary(int s)
    {
        this->salary = s;
    }
    int getSalary()
    {
        return salary;
    }

    void setDepartment(string d)
    {
        this->department = d;
    }
    string getDepartment()
    {
        return department;
    }

    void setDegree(string degree)
    {
        this->degree = degree;
    }
    string getDegree()
    {
        return degree;
    }
};
class Course
{
private:
    string courseName;
    int courseHours;
    int courseCode;
    string professor;

public:
    // default contructor
    Course()
    {
        cout << "Course default constructor" << endl;
    }

    Course(string courseName, int courseHours, int courseCode, string professor)
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
    void setCourseCode(int courseCode)
    {
        this->courseCode = courseCode;
    }
    void setCourseHours(int courseHours)
    {
        this->courseHours = courseHours;
    }
    void setProfessor(string professor)
    {
        this->professor = professor;
    }

    string getCoursename()
    {
        return courseName;
    }
    int getCourseHours()
    {
        return courseHours;
    }
    int getCourseCode()
    {
        return courseCode;
    }
    string getProffesor()
    {
        return professor;
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
    void addCourses(string courseName, int courseHours, int courseCode, string professor)
    {
        Course course(courseName, courseHours, courseCode, professor);
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
    void SearchCourse(int coursecode)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (coursecode == courses[i].getCourseCode())
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
    void addProfessors(int id, int salary, string department, string degree)
    {
        Professor professor(id, salary, department, degree);
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
                cout << "Professor ID: " << professors[i].getId() << " Professor Salary: " << professors[i].getSalary() << " Professor Department: " << professors[i].getDepartment() << " Professor: " << professors[i].getDegree() << endl;
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
    void addStudent(int id ,int level, float gpa)
    {
        Student student(id,level, gpa);
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
                cout << "ID: " << students[i].getId() << " Level: " << students[i].getLevel() << " GPA: " << students[i].getGpa() << endl;
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
};
University *University::instancePtr = NULL;

int main()
{
    University *uni = University::getInstance();

    bool exit = false;
    while (!exit)
    {
        int choice = 0;
        cout << "\nSelect an option:\n\n";
        cout << "(1) : Details of the Student\n";
        cout << "(2) : Details of the Department\n";
        cout << "(3) : Details of the Professor\n";
        cout << "(4) : Details of the Courses\n";

        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int exit = 1;
            while (exit != 0 && exit == 1)
            {

                int id, level;
                float gpa;
                cout << "Enter Your ID" << endl;
                cin >> id;

                cout << "Enter Your Level" << endl;
                cin >> level;

                cout << "Enter Your GPA" << endl;
                cin >> gpa;

                uni->addStudent(id, level, gpa);

                cout << "Enter 0 for exit or 1 for continue to adding Student..." << endl;
                cin >> exit;
            }
            uni->printStudents();

            int index, newId, newLevel;
            float newGPA;

            cout << "Enter the index of the student you want to update: " << endl;
            cin >> index;
            cout << "Enter the new GPA: " << endl;
            cin >> newGPA;

            uni->updateStudent(index, newGPA);

            uni->printStudents();
            int id;
            cout << "Enter your id for search..." << endl;
            cin >> id;
            uni->SearchStudent(id);

            int deleteIndex;
            cout << "Enter the index of the student you want to delete: " << endl;
            cin >> deleteIndex;

            uni->deleteStudent(deleteIndex);
            uni->printStudents();
        }
        else if (choice == 2)
        {
            int exit = 1;
            while (exit != 0 && exit == 1)
            {

                string name;
                int capacity;
                int requiredGPA;
                cout << "Enter Department Name" << endl;
                cin >> name;

                cout << "Enter Department Capacity" << endl;
                cin >> capacity;

                cout << "Enter Required GPA" << endl;
                cin >> requiredGPA;

                uni->addDepartment(name, capacity, requiredGPA);

                cout << "Enter 0 for exit or 1 for continue to adding Departments..." << endl;
                cin >> exit;
            }
            uni->printDepartment();

            int index, newrequiredGPA;

            cout << "Enter the index of the student you want to update: " << endl;
            cin >> index;
            cout << "Enter the Required GPA: " << endl;
            cin >> newrequiredGPA;

            uni->updateDepartment(index, newrequiredGPA);

            uni->printDepartment();
            string name;
            cout << "Enter Department Name for search..." << endl;
            cin >> name;
            uni->SearchDepartment(name);

            int deleteIndex;
            cout << "Enter the index of the Department you want to delete: " << endl;
            cin >> deleteIndex;

            uni->deleteDepartment(deleteIndex);
            uni->printDepartment();
        }
        else if (choice == 3)
        {
            int exit = 1;
            while (exit != 0 && exit == 1)
            {

                int id;
                int salary;
                string department;
                string degree;
                cout << "Enter Professor ID" << endl;
                cin >> id;

                cout << "Enter Professor Salary" << endl;
                cin >> salary;

                cout << "Enter Professor Department" << endl;
                cin >> department;

                cout << "Enter Professor Degree" << endl;
                cin >> degree;

                uni->addProfessors(id, salary, department, degree);

                cout << "Enter 0 for exit or 1 for continue to adding Profeesors..." << endl;
                cin >> exit;
            }
            uni->printProfessor();

            int index, newsalary;

            cout << "Enter the index of the Professor you want to update: " << endl;
            cin >> index;
            cout << "Enter Salary: " << endl;
            cin >> newsalary;

            uni->updateProfessor(index, newsalary);

            uni->printProfessor();
            int id;
            cout << "Enter Professor ID for search..." << endl;
            cin >> id;
            uni->SearchProfessor(id);

            int deleteIndex;
            cout << "Enter the index of the Professor you want to delete: " << endl;
            cin >> deleteIndex;

            uni->deleteProfessor(deleteIndex);
            uni->printProfessor();
        }
        else if (choice == 4)
        {
            int exit = 1;
            while (exit != 0 && exit == 1)
            {

                string coursename;
                int coursehour;
                int coursecode;
                string profdegree;
                cout << "Enter Course Name" << endl;
                cin >> coursename;

                cout << "Enter Course Course Hour" << endl;
                cin >> coursehour;

                cout << "Enter Course Code" << endl;
                cin >> coursecode;

                cout << "Enter Professor Degree" << endl;
                cin >> profdegree;

                uni->addCourses(coursename, coursehour, coursecode, profdegree);

                cout << "Enter 0 for exit or 1 for continue to adding Profeesors..." << endl;
                cin >> exit;
            }
            uni->PrintCourses();

            int index, newcourseHour;

            cout << "Enter the index of the Course you want to update: " << endl;
            cin >> index;
            cout << "Enter Course Hour: " << endl;
            cin >> newcourseHour;

            uni->updateCourse(index, newcourseHour);

            uni->PrintCourses();
            int courseCode;
            cout << "Enter Course Code for search..." << endl;
            cin >> courseCode;
            uni->SearchProfessor(courseCode);

            int deleteIndex;
            cout << "Enter the index of the Course you want to delete: " << endl;
            cin >> deleteIndex;

            uni->deleteCourse(deleteIndex);
            uni->PrintCourses();
        }
        else if (choice == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
