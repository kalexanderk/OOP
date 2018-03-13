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
        Date& modDay(int);
        Date& modMonth(int);
        Date& modYear(int);
        ~Date(){};
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
};

class Customer{
    private:
        char *name, *theme;
        int price;
    public:
        Customer();
        Customer(const char*, const char*, int);
        Customer(const Customer&);
        const char* getName() const;
        const char* getTheme() const;
        int getPrice() const;
        char *out() const;
        Customer& modName(const char*);
        Customer& modTheme(const char*);
        Customer& modPrice(int);
        ~Customer();
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
};

class Research{
    private:
        Customer* customer;
        Date* sign_date;
        Publication** publications;
        int num_of_publications;
        //char * theme;
    public:
        Research();
        Research(const Customer&, const Date&);
        Research(const Research&);
        const Customer& getCustomer() const;
        const Date& getSignDate() const;
        int getNumOfPublications() const;
        const Publication* const* getPublicationList() const;
        //const char * getTheme() const;
        char * getInfo() const;
        char * out() const;
        Research& addPublication(const Publication&);
        Research& modCustomer(const Customer&);
        ~Research();
};
