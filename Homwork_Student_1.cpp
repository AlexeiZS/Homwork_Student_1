// Homwork_Student_1.cpp 
/*
создать класс студент
студент имеет имя фамилию отчество
оценки по матеметике
оценки по физике
выставить оценку (по мат, по рус,по физ)
исправить оценку(по индексу)
вывод оценок
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Student_1
{
private:
	string surname;
	string name;
	string patronymic;
	int* mark_mat = nullptr;
	int* mark_physic = nullptr;
	int* mark_rusian = nullptr;
	int countMat = 0;
	int countPhysic = 0;
	int countRusian = 0;
public:
	Student_1(){}
	Student_1(string surname, string name, string patronymic)
	{
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
	}
	~Student_1()
	{
		cout << " Отработал деструктор Student."<< endl;
		//освобождение памяти для оценок.
		if (mark_mat != nullptr) {
			delete[]mark_mat;
		}
		if (mark_physic != nullptr) {
			delete[]mark_physic;
		}
		if (mark_rusian != nullptr) {
			delete[]mark_rusian;
		}
	}
	void setMarkMat(int mark)
	{
		if (!countMat) {
			mark_mat = new int[1];
			mark_mat[0] = mark;
		}
		else
		{
			int* buf = new int[countMat + 1];
			for (int i = 0; i < countMat + 1; i++) {
				buf[i] = mark_mat[i];
			}
			buf[countMat] = mark;
			delete[]mark_mat;
			mark_mat = buf;
		}
		countMat++;
	}
	void setMarkPhysic(int mark)
	{
		if (!countPhysic) {
			mark_physic = new int[1];
			mark_physic[0] = mark;
		}
		else
		{
			int* buf = new int[countPhysic + 1];
			for (int i = 0; i < countPhysic + 1; i++) {
				buf[i] = mark_physic[i];
			}
			buf[countPhysic] = mark;
			delete[]mark_physic;
			mark_physic = buf;
		}
		countPhysic++;
	}
	void setMarkRusian(int mark)
	{
		if (!countRusian)
		{
			mark_rusian = new int[1];
			mark_rusian[0] = mark;
		}
		else
		{
			int* buf = new int[countRusian + 1];
			for (int i = 0; i < countRusian + 1; i++) {
				buf[i] = mark_rusian[i];
			}
			buf[countRusian] = mark;
			delete[]mark_rusian;
			mark_rusian = buf;
		}
		countRusian++;
	}
	void setStudent()
	{
		cout << " Фамилия: ";
		cin >> surname;
		cout << " Имя:";
		cin >> name;
		cout << " Отчество:";
		cin >> patronymic;
	}
	void setRatings()
	{
		char x;
		do
		{
			cout << "  Выберите предмет (Математика 1, Физика 2, Русский 3) :" << endl;
			int a, mark;
			cin >> a;
			// a=choice(); // выбор.
			switch (a)
			{
			case 1:
				cout << " Вы выбрали Математику."
					<< endl << "(по окончанию ввода нажмите NULL)"
					<< endl << "Введите оценки : " << endl;
				while (true) {
					cin >> mark;
					if (mark >= 1 && mark <= 12)
						setMarkMat(mark);
					else break;
				}
				break;
			case 2:
				cout << " Вы выбрали Физику."
					<< endl << "(по окончанию ввода нажмите NULL)"
					<< endl << "Введите оценки : " << endl;
				while (true) {
					cin >> mark;
					if (mark >= 1 && mark <= 12)
						setMarkPhysic(mark);
					else break;
				}
				break;
			case 3:
				cout << " Вы выбрали Русский."
					<< endl << "(по окончанию ввода нажмите NULL)"
					<< endl << "Введите оценки : " << endl;
				while (true) {
					cin >> mark;
					if (mark >= 1 && mark <= 12)
						setMarkRusian(mark);
					else break;
				}
				break;
			default:
				cout << " Вы ошиблись, попробуйте ещё раз." << endl;
			}
			cout << " Продолжить ввод оценок ( y / n )";
			cin >> x;
		} while (x == 'y');
	}
	//выбор предмета.
	int* choice()
	{
		int x;
		cout << "  Выберите предмет (Математика 1, Физика 2, Русский 3) :" << endl;
		cin >> x;
		switch (x) {
		case 1:
			cout << " Математика: " << endl;
			return mark_mat;
			break;
		case 2:
			cout << " Физика:" << endl;
			return mark_physic;
			break;
		case 3:
			cout << " Русский:" << endl;
			return mark_rusian;
			break;
		}
	}
	
	void setCorrectGrades()
	{
		int ipos,newmark;
		int* markAr = choice();
		cout << " Исправление оценок: ";
		getMark(markAr);   // вывод оценок.
		cout << " Введите позицию оценки (1,2 или 3 и т.д) для исправления:";
		cin >> ipos;
		cout << " Введите новую оценку:";
		cin >> newmark;
		int size = _msize(markAr) / sizeof(markAr[0]);
		if (ipos > 0 and ipos <= size)
			markAr[ipos - 1] = newmark;

	}

    void getStudFIO()
    {
		cout << " Ф.И.О. " << surname<<" "<<name<<" "<<patronymic<< endl;
    }

	void getMark(int* ar)
	{
		int size = _msize(ar) / sizeof(ar[0]);
		for (int i = 0; i < size; i++)
			cout << ar[i] << " ";
		cout << endl;
	}

	void getStudMark()
	{
		if (countMat) {
			cout <<setw(14)<< " Математика : ";
			for (int i = 0; i < countMat; i++)
				cout << mark_mat[i] << " ";
			cout << endl;
		}
		if (countPhysic)
		{
			cout << setw(14)<<" Физика : ";
			for (int i = 0; i < countPhysic; i++)
				cout << mark_physic[i] << " ";
			cout << endl;
		}
		if (countRusian)
		{
			cout <<setw(14)<< " Русский : ";
			for (int i = 0; i < countRusian; i++)
				cout << mark_rusian[i] << " ";
			cout << endl;
		}
	}



};


int main()
{
	setlocale(LC_ALL, "ru");
	Student_1 st1;
	int x;
		cout << " \t\tСоздаем класс студент." << endl;
		st1.setStudent();     //ввод ФИО.
		st1.setRatings();     //выставить оценки.
		st1.getStudFIO();     //вывод ФИО.
		st1.getStudMark();    //вывод оценок.
	do {
		cout << " Выставить (добавить) оценку: 1 " << endl
			 << " Исправить оценку: 2 " << endl
			 << " Вывод инф. о студенте: 3"<<endl
			 << " Выход: 4 " << endl;
		cin >> x;
		switch(x) {
			case 1:
				st1.setRatings();
				break;
			case 2:
				st1.setCorrectGrades();
				break;
			case 3:
				st1.getStudFIO();
				st1.getStudMark();
				break;
			case 4:
				cout << " Досвидание." << endl;
				break;
		}

	} while (x!=4);



	return 0;
}

