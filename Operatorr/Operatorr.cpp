


#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class MyString {
    char* st;
    static int amount;
    int size;

public:
    MyString() {
        st = new char[80]();
        amount++;
    }

    MyString(int size) {
        this->size = size;
        st = new char[this->size + 1];
        amount++;
    }

    void String(const char* ad) {

        st = new char[strlen(ad) + 1];
        strcpy_s(st, strlen(ad) + 1, ad);
    }
    MyString(const MyString& obj) {
        st = new char[strlen(obj.st) + 1];
        strcpy_s(st, strlen(obj.st) + 1, obj.st);
    }
    MyString operator=(const MyString& obj) {
        if (!(this == &obj)) {
            if (st != nullptr) {
                delete[] st;
            }
            if (obj.st == nullptr) {
                st = nullptr;
           
                size = obj.size;
                return *this;
            }
            st = new char[strlen(obj.st) + 1];
            strcpy_s(st, strlen(obj.st) + 1, obj.st);
            amount = obj.amount;
            size = obj.size;
        }
        return *this;
    }
    MyString operator++(int) {

        char* temp = new char[strlen(st) + 2];
        strcpy_s(temp, strlen(st) + 2, st);
        temp[strlen(st)] = 'x';
        temp[strlen(st) + 1] = '\0';
        delete[] st;
        st = temp;
        return  *this;
    }
    MyString operator--(int) {
        int amount = 2;
        char* temp = new char[strlen(st) - amount + 1];
        strcpy_s(temp, strlen(st) - amount + 1, st);
        temp[strlen(st) - 1] = '\0';
        delete[] st;
        st = temp;
        return *this;
    }

    static int GetAmount() {
        return amount;
    }

    void Prin() const {
        cout << "String: " << st << endl;
        cout << "Amount: " << amount << endl;
    }

    ~MyString() {
        delete[] st;
        amount--;
    }
};
int MyString::amount = 0;
class Contacts {
    char* fi;
    int workphone;
    int homephone;
    int phone;
    char* info;

public:
    Contacts() {
        fi = nullptr;
        workphone = 0;
        homephone = 0;
        phone = 0;
        info = nullptr;
    }
    Contacts(const char* name, int work, int home, int phone, const char* inf) {
        fi = new char[strlen(name) + 1];
        strcpy_s(fi, strlen(name) + 1, name);
        workphone = work;
        homephone = home;
        this->phone = phone;
        info = new char[strlen(inf) + 1];
        strcpy_s(info, strlen(inf) + 1, inf);
    }
    Contacts(const Contacts& obj) {
        fi = new char[strlen(obj.fi) + 1];
        strcpy_s(fi, strlen(obj.fi) + 1, obj.fi);
        workphone = obj.workphone;
        homephone = obj.homephone;
        phone = obj.phone;
        info = new char[strlen(obj.info) + 1];
        strcpy_s(info, strlen(obj.info) + 1, obj.info);
    }
    void Check() {
        if (fi != nullptr) {
            delete[] fi;
        }
    }
    void Cheak() {
        if (info != nullptr) {
            delete[] info;
        }
    }
    void Cout() {
        if (fi == nullptr && info == nullptr) {
            cout << "Nothing" << endl;
            return;
        }
        cout << "Fio: " << fi << "\n";
        cout << "Workphone: " << workphone << "\n";
        cout << "Homephone: " << homephone << "\n";
        cout << "Contact phone: " << phone << "\n";
        cout << "Information: " << info << "\n";
    }

    ~Contacts() {

    }
    Contacts operator=(const Contacts& obj) {
        if (!(this == &obj)) {
            if (fi != nullptr && info != nullptr) {
                delete[] fi;
                delete[] info;
            }
            if (obj.fi == nullptr && obj.info == nullptr) {
                fi = nullptr;
                info == nullptr;
                workphone = obj.workphone;
                homephone = obj.homephone;
                phone = obj.homephone;
                return *this;

            }
            fi = new char[strlen(obj.fi) + 1];
            strcpy_s(fi, strlen(obj.fi) + 1, obj.fi);
            workphone = obj.workphone;
            homephone = obj.homephone;
            phone = obj.phone;
            info = new char[strlen(obj.info) + 1];
            strcpy_s(info, strlen(obj.info) + 1, obj.info);
        }
        return *this;
    }
};

void Print(Contacts* fio) {
    for (int i = 0; i < 3; i++) {
        fio[i].Cout();
    }
}
void addStudents(Contacts ar[], int size) {
    Contacts* arr = new Contacts[size + 1];

    for (int i = 0; i < size; i++) {
        arr[i] = ar[i];
    }
    arr[size] = Contacts("Ilushenko, Nikita, Andreevich", 453535, 654654654, 456465, "Best student");
    for (int i = 0; i < size + 1; i++) {
        arr[i].Cout();
    }

    delete[] arr;
}
void deleteStudents(Contacts ar[], int size, int delcont) {
    Contacts* arr = new Contacts[size - 1];

    for (int i = 0; i < size; i++) {
        arr[i] = ar[i];
    }
    int i = delcont + 1;
    while (i < size) {
        arr[i - 1] = ar[i];
        i++;
    }
    for (int i = 0; i < size; i++) {
        arr[i].Cout();
    }
    delete[] arr;
    size--;
    
}

int main()
{
    
    
    
    //N3
    int size = 3;
    int delcont = 1;
    Contacts* fio = new  Contacts[size];
    fio[0] = Contacts("Ivanov, Ivan, Ivanovich ", 654646456, 232312342, 34897789, "Graphic designer for 10 years");
    fio[1] = Contacts("Pertov, Anatoly, Sergeevich ", 658465409, 43278974, 342423, "Engineer in Microsoft");
    fio[2] = Contacts("Lyakhovetskyi, Leonid, Leonidovich ", 34243243, 9650806, 214124, "Best mentor in computer academy IT-STEP");
    //Print(fio);
    //addStudents(fio, size);
    //deleteStudents(fio, size, delcont);

    Contacts* P2 = fio;
    //Print(P2);
    Contacts* A;
    A = fio;
    Print(A);
    delete[] fio;
    //N1
    MyString obj;
    MyString obj2(100);
    MyString obj3;
    obj3.String("Andrey");

    obj3.GetAmount();

    obj3.Prin();
    MyString b = obj3;
    b.Prin();
    MyString X;
    X = obj3;
    X.Prin();
    //N2
    MyString obj5 = obj3++;
    obj5.Prin();
    MyString obj6 = obj3--;
    obj5.Prin();
}


