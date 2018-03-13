#include <iostream> //just for defining a types std::ostream& and std::istream&
class Date{
    private:
        int day, month, year;
    public:
        Date();
	Date(int, int, int);
        Date(const Date&);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        char *out() const;
        Date operator+(const Date&);
        Date& modDay(int);
        Date& modMonth(int);
        Date& modYear(int);
        ~Date();
        static bool verify(const int*);
};

class Student{
    private:
        char *name, *surname;
        int enroll_year;
    public:
        Student();
        Student(const char*, const char*, int);
        Student(const Student&);
        const char* getName() const;
        const char* getSurname() const;
        int getEnrollYear() const;
        char* out() const;
        Student& modName(const char *);
        Student& modSurname(const char *);
        Student& modEnrollYear(int);
        ~Student();
        bool operator==(const Student&);
        bool operator!=(const Student&);
        friend std::ostream& operator <<(std::ostream&, const Student&);
        friend std::istream& operator >>(std::istream&, Student&);
        Student& operator=(const Student& rhs);
};

//полиморфные классы допускают обработку объектов, тип которых неизвестен во время компиляции
class Customer{
    protected:
        char *name, *theme;
        int price;
    public:
        Customer();
        Customer(const char*, const char*, int);
        Customer(const Customer&);
        const char* getName() const;
        const char* getTheme() const;
        int getPrice() const;
        virtual char *out() const; // if virtual is removed from the declaration, in all cases the version of the base
                                   //class would  have been called instead
        //Функции, описанные в базовом классе как виртуальные, могут быть модифицированы в производных классах, причем связывание 
        //произойдет не на этапе компиляции (то, что называется ранним связыванием), а в момент обращения к 
        //данному методу (позднее связывание). 
        Customer& modName(const char*);
        Customer& modTheme(const char*);
        Customer& modPrice(int);
        virtual ~Customer();
        Customer& operator=(const Customer&);
};

enum SciAchivment {THESIS, ARTICLE, REPORT, INTARTICLE};

class Publication{
    private:
        Student* author;
        SciAchivment pub_type;
    public:
        Publication();
        Publication(const Student&, const SciAchivment);
        Publication(const Publication&);
        const Student& getAuthor() const;
        SciAchivment getPublicationType() const;
        char * out() const;
        Publication& modAuthor(const Student&);
        Publication& modPublicationType(const SciAchivment);
        ~Publication();
        friend std::ostream& operator<<(std::ostream&, const Publication&);
        friend std::istream& operator>>(std::istream&, Publication&);
        Publication& operator=(const Publication&);
};

class Research: public Customer{
    private:
        Date* sign_date;
        Publication** publications;
        int num_of_publications;
    public:
        Research();
        Research(const Customer&, const Date&);
        Research(const Research&);
        bool operator>(const Research&);
        bool operator<(const Research&);
        const Date& getSignDate() const;
        int getNumOfPublications() const;
        const Publication* const* getPublicationList() const;
        char * getInfo() const;
        char *out() const;
        Research& addPublication(const Publication&);
        Research& modCustomer(const Customer&);
        char const* operator[](int);
        ~Research();
        Research& operator=(const Research&);
};
