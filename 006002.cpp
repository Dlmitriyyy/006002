#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person
{
protected:
	long int un_id;
	string name, sname, num_pass, date_of_birth, more_info;
public:
	Person() : un_id(0), name(""), sname(""), num_pass(""), date_of_birth(""), more_info("")
	{

	}
	Person(unsigned long int count, long int un_id, string name, string sname, string num_pass, string date_of_birth, string more_info)
	{
		this->un_id = un_id;
		this->name = name;
		this->sname = sname;
		this->num_pass = num_pass;
		this->date_of_birth = date_of_birth;
		this->more_info = more_info;
	}
	void set_info(unsigned long int count, long int un_id, string name, string sname, string num_pass, string date_of_birth, string more_info)
	{
		this->un_id = un_id;
		this->name = name;
		this->sname = sname;
		this->num_pass = num_pass;
		this->date_of_birth = date_of_birth;
		this->more_info = more_info;
	}
	void show_info()
	{
		cout << endl << endl << "Унікальний РНОКПП    : " << un_id;
		cout << endl << "Ім'я                 : " << name;
		cout << endl << "Прізвище             : " << sname;
		cout << endl << "Номер паспорта       : " << num_pass;
		cout << endl << "Дата народження      : " << date_of_birth;
		cout << endl << "Додаткова інформація : " << more_info;
	}
};
class Students : public Person
{
protected: 
	static unsigned long int count;
	string school;
	string specialty;
	string group;
public:
	Students() : school(""), specialty(""), group("")
	{

	}
	Students(unsigned long int count, long int un_id, string name, string sname, string num_pass, string date_of_birth, string more_info, string school, string speciality, string group) : Person(count, un_id, name, sname, num_pass, date_of_birth, more_info)
	{
		this->school = school;
		this->specialty = speciality;
		this->group = group;
		count++;
	}
	void set_info(unsigned long int count, long int un_id, string name, string sname, string num_pass, string date_of_birth, string more_info, string school, string speciality, string group)
	{
		Person::set_info(count, un_id, name, sname, num_pass, date_of_birth, more_info);
		this->school = school;
		this->specialty = speciality;
		this->group = group;
	}
	static void reset_count()
	{
		count = 1;
	}
	void show_info()
	{
		cout << endl << "Номер студента по порядку - " << count++;
		Person::show_info();
		cout << endl << "Навчальний заклад    : " << school;
		cout << endl << "Спеціальність        : " << specialty;
		cout << endl << "Група                : " << group << endl;
	}
	};

unsigned long int Students::count = 1;

int main()
{
	system("chcp 1251 > nul");
	int more_students;
	unsigned long int count = 1;
	long int un_id;
	string name, sname, num_pass, date_of_birth, more_info, school, speciality, group;
	vector<Students> students_info;
	cout << "Ця програма просить користувача ввести дані про студентів, зберігає їх у векторі і виводить інформацію на екран." << endl;
	do
	{
		cout << endl << "Введіть унікальний РНОКПП: ";
		while (true)
		{
			if (cin >> un_id && un_id >= 0)
			{
				break;
			}
			else
			{
				cout << endl << "Помилка, РНОКПП має містити лише додатні числа, спробуйте знову: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		cin.ignore();
		cout << endl << "Введіть ім'я студента: ";
		getline(cin, name);
		cout << endl << "Введіть прізвище студента: ";
		getline(cin, sname);
		cout << endl << "Введіть номер паспорта: ";
		getline(cin, num_pass);
		cout << endl << "Введіть дату народження: ";
		getline(cin, date_of_birth);
		cout << endl << "Вкажіть додаткову інформацію про студента, де навчався раніше: ";
		getline(cin, more_info);
		cout << endl << "Вкажіть в якому навчальному закладі навчається у даний момент: ";
		getline(cin, school);
		cout << endl << "Вкажіть спеціальність: ";
		getline(cin, speciality);
		cout << endl << "Вкажіть номер групи до якої входить студент: ";
		getline(cin, group);

		Students student(count, un_id, name, sname, num_pass, date_of_birth, more_info, school, speciality, group);
		students_info.push_back(student);

		cout << endl << endl << "Якщо бажаєте додати ще одного студента введіть 1, щоб завершити програму введіть іншу цифру: ";
		cin >> more_students;
		cout << endl;
	} 

	while (more_students == 1);

		for (Students& student : students_info)
		{
			
			student.show_info();
		}

		return 0;
}