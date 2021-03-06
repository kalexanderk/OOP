#include "lab1mod.hpp"
#include <stdio.h>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <regex>
//For debugging
//#include <iostream>

//--------------------------------------------------

//CONSTRUCTORS DATE

Date::Date(){
    //std::time_t time( std::time_t* arg ) - returns the current calendar time encoded as a std::time_t object, and also stores it
    //in the object pointed to by arg, unless arg is a null pointer.
    std::time_t now = std::time(NULL);
    //struct tm* - pointer on time structure; structure containing a calendar date and time broken down into its components.
    //struct tm * localtime (const time_t * timer) - uses the value pointed by timer to fill a tm structure with the values that
    //represent the corresponding time, expressed for the local timezone.
    struct tm* tstruct = std::localtime(&now); 
    //and now aggign values from received structure-calendar
    this->day = tstruct->tm_mday;
    this->month = tstruct->tm_mon + 1;
    this->year = tstruct->tm_year + 1900;
    return ;
};

Date::Date(int in_day, int in_month, int in_year){
    this->day = in_day;
    this->month = in_month;
    this->year = in_year;
    return ;
}

//constructor of copy
Date::Date(const Date& in_date){
    this->day = in_date.getDay(); //as fields day, month, year are private; we can change 'em only with the class methods
    this->month = in_date.getMonth();
    this->year = in_date.getYear();
    return ;
}

//CONSTRUCTORS DATE

int Date::getDay() const{
    return this->day;
}

int Date::getMonth() const{
    return this->month;
}

int Date::getYear() const{
    return this->year;
}

//date output in string representation
char * Date::out() const{
    char * res = new char[10];
    sprintf(res, "%02i.%02i.%04i", this->day, this->month, this->year);
    return res;
}

//modifications of day, month, year
Date& Date::modDay(int inday){
    this->day = inday;
    return *this;
}

Date & Date::modMonth(int in_month){
    this->month = in_month;
    return *this;
}

Date& Date::modYear(int in_year){
    this->year = in_year;
    return *this;
}
//

//check whether the date is correct
bool Date::verify(const int * in_date){
    if (! (1582<= *(in_date + 2) )  )
        return false;
    if (! (1<= *(in_date + 1) && *(in_date + 1)<=12) )
        return false;
    if (! (1<= *(in_date) && *(in_date)<=31) )
        return false;
    if ( (*(in_date)==31) && (*(in_date + 1)==2 || *(in_date + 1)==4 || *(in_date + 1)==6 || *(in_date + 1)==9 || *(in_date + 1)==11) )
        return false;
    if ( (*(in_date)==30) && (*(in_date + 1)==2) )
        return false;
    if ( (*(in_date + 1)==2) && (*(in_date)==29) && (*(in_date + 2)%4!=0) )
        return false;
    if ( (*(in_date + 1)==2) && (*(in_date)==29) && (*(in_date + 2)%400==0) )
        return true;
    if ( (*(in_date + 1)==2) && (*(in_date)==29) && (*(in_date + 2)%100==0) )
        return false;
    if ( (*(in_date + 1)==2) && (*(in_date)==29) && (*(in_date + 2)%4==0)  )
        return true;
    return true;
}

//--------------------------------------------------

//--------------------------------------------------

//CONSTRUCTORS STUDENT
Student::Student(){
    this->name = new char[sizeof "Name"];
    this->surname = new char[sizeof "Surname"];
    std::strcpy(this->name, "Name");
    std::strcpy(this->surname, "Surname");
    //
    std:: time_t now = std::time(NULL);
    struct tm *tstruct = std::localtime(&now);
    //
    this->enroll_year = 1900 + tstruct->tm_year;
    return ;
}

Student::Student(const char * in_name, const char * in_surname, int in_year){
    this->name = new char[sizeof in_name];
    this->surname = new char[sizeof in_surname];
    std::strcpy(this->name, in_name);
    std::strcpy(this->surname, in_surname);
    this->enroll_year = in_year;
    return ;
}

//constructor of copy
Student::Student(const Student& in_student){
    this->name = new char[sizeof in_student.name];
    this->surname = new char[sizeof in_student.surname];
    std::strcpy(this->name, in_student.name);
    std::strcpy(this->surname, in_student.surname);
    this->enroll_year = in_student.enroll_year;
    return ;
}
//CONSTRUCTORS STUDENT

//DESTRUCTOR STUDENT
Student::~Student(){
    //free memory
    delete[] this->name;
    delete[] this->surname;
    return ;
}

const char * Student::getName() const{
    return (const char *)this->name;
}

const char * Student::getSurname() const{
    return (const char *)this->surname;
}

int Student::getEnrollYear() const{
    return this->enroll_year;
}

//output full info about student
char * Student::out() const{
    char * res = new char[(std::strlen(this->name) + 1) + (std::strlen(this->surname) + 1) + 6];
    sprintf(res, "%s %s\n%04i",
                        this->name, this->surname, this->enroll_year); //sends formatted output to a string res
    return res;
}

//modife student's name
Student& Student::modName(const char * in_name){
    delete[] this->name;
    this->name = new char[sizeof in_name];
    std::strcpy(this->name, in_name);
    return *this;
}

Student& Student::modSurname(const char * in_surname){
    delete[] this->surname;
    this->surname = new char[sizeof in_surname];
    std::strcpy(this->surname, in_surname);
    return *this;
}

Student & Student::modEnrollYear(int inyear){
    this->enroll_year = inyear;
    return *this;
}

//--------------------------------------------------

//--------------------------------------------------

//CONSTRUCTORS CUSTOMER

Customer::Customer(){
    this->name = new char[sizeof "Name"];
    this->theme = new char[sizeof "Theme"];
    std::strcpy(this->name, "Name");
    std::strcpy(this->theme, "Theme");
    this->price = 0;
    return ;
}

Customer::Customer(const char * in_name, const char * in_theme, int in_price){
    this->name = new char[sizeof in_name];
    this->theme = new char[sizeof in_theme];
    std::strcpy(this->name, in_name);
    std::strcpy(this->theme, in_theme);
    this->price = in_price;
    return ;
}

//constructor of copy
Customer::Customer(const Customer& in_research){
    this->name = new char[sizeof in_research.name];
    this->theme = new char[sizeof in_research.theme];
    std::strcpy(this->name, in_research.name);
    std::strcpy(this->theme, in_research.theme);
    this->price = in_research.price;
    return ;
}
//CONSTRUCTORS CUSTOMER

//DESTRUCTOR CUSTOMER
Customer::~Customer(){
    delete[] this->name;
    delete[] this->theme;
    return ;
}

const char * Customer::getName() const{
    return (const char *)this->name;
}

const char * Customer::getTheme() const{
    return (const char *)this->theme;
}

int Customer::getPrice() const{
    return this->price;
}

//output full info about customer
char * Customer::out() const{
    char * res = new char[(std::strlen(this->name) + 1) + (std::strlen(this->theme) + 1) + 6];
    sprintf(res, "%s %s\n%04i",
                        this->name, this->theme, this->price);
    return res;
}

Customer & Customer::modName(const char * in_name){
    delete[] this->name;
    this->name = new char[sizeof in_name];
    std::strcpy(this->name, in_name);
    return *this;
}

Customer & Customer::modTheme(const char * in_theme){
    delete[] this->theme;
    this->theme = new char[sizeof in_theme];
    std::strcpy(this->theme, in_theme);
    return *this;
}

Customer & Customer::modPrice(int in_price){
    this->price = in_price;
    return *this;
}

//--------------------------------------------------

//--------------------------------------------------

//CONSTRUCTORS PUBLICATION

Publication::Publication(){
    this->author = new Student();
    this->pub_type = THESIS;
};

Publication::Publication(const Student& in_author, const SciAchivment in_pub_type){
    this->author = new Student(in_author);//initialize Student with some name in_author
    this->pub_type = in_pub_type;
};

//constructor of copy
Publication::Publication(const Publication& in_publication){
    this->author = new Student(in_publication.getAuthor());
    this->pub_type = in_publication.getPublicationType();
};

//CONSTRUCTORS PUBLICATION

//get author
const Student& Publication::getAuthor() const{
    return *(this->author);
};

//get publication type
SciAchivment Publication::getPublicationType() const{
    return this->pub_type;
};

//output all info about Publication
char * Publication::out() const{
    char * a_name = this->author->out();
    char * p_name;
    switch(this->pub_type){
        case THESIS : p_name = new char[sizeof "thesis for report"];
                      std::strcpy(p_name, "thesis for report");
                      break;
        case ARTICLE : p_name = new char[sizeof "article in proffesional journal"];
                       std::strcpy(p_name, "article in proffesional journal");
                       break;
        case REPORT : p_name = new char[sizeof "report on conference"];
                      std::strcpy(p_name, "report on conference");
                      break;
        case INTARTICLE : p_name = new char[sizeof "article in an international science journal"];
                          std::strcpy(p_name, "article in an international science journal");
                          break;
    };
    char * res = new char[(std::strlen(a_name) + 1) + (std::strlen(p_name) + 1) + sizeof "\nPublication type : "];
    std::strcpy(res, a_name);
    std::strcat(res, "\tPublication type : ");
    std::strcat(res, p_name);
    delete[] p_name;
    delete[] a_name;
    return res;
};

//change author
Publication& Publication::modAuthor(const Student & in_author){
    delete this->author;
    this->author = new Student(in_author);
    return *this;
};

//change publication type
Publication& Publication::modPublicationType(const SciAchivment in_pub_type){
    this->pub_type = in_pub_type;
    return *this;
};

//DESTRUCTOR PUBLICATION
Publication::~Publication(){
    delete this->author;
};

//--------------------------------------------------

//--------------------------------------------------

//CONSTRUCTORS RESEARCH

Research::Research(){
    this->customer = new Customer();
    this->sign_date = new Date();
    this->num_of_publications = 0;
    this->publications = NULL;
};

Research::Research(const Customer& in_customer, const Date& in_date){
    this->customer = new Customer(in_customer);
    this->sign_date = new Date(in_date);
    this->num_of_publications = 0;
    this->publications = NULL;
};

Research::Research(const Research& in_research){
    this->customer = new Customer(in_research.getCustomer());
    this->sign_date = new Date(in_research.getSignDate());
    this->num_of_publications = in_research.getNumOfPublications();
    this->publications = new Publication*[this->num_of_publications];
    const Publication * const * retireved = in_research.getPublicationList();
    for (int i=0; i++; i < this->num_of_publications){
        *(this->publications + i) = new Publication(**(retireved + i));
    };
};

//CONSTRUCTORS RESEARCH

const Customer & Research::getCustomer() const{
    return *(this->customer);
};

const Date & Research::getSignDate() const{
    return *(this->sign_date);
};

int Research::getNumOfPublications() const{
    return this->num_of_publications;
};

const Publication * const * Research::getPublicationList() const{
    return this->publications; 
};

char * Research::getInfo() const{
    const char * theme = this->customer->getTheme();
    char * res = new char[(std::strlen(theme) + 1) +
                          sizeof "theme: \nnum of publications:" +
                          (sizeof (char))*(int)(std::log(this->num_of_publications ?
                                                            this->num_of_publications != 0 :
                                                            1)
                                                / std::log(10))];
    sprintf(res, "theme: %s\nnum of publications: %i",
                 theme, this->num_of_publications);
    return res;
};

char * Research::out() const{
    //God-like code
    //getting fields out-strings
    char * customer_out = this->customer->out();
    char * date_out = this->sign_date->out();
    char * nop_out = new char[sizeof "\nNumber of all publications" +
                              (int)(1 + std::log((this->num_of_publications != 0 )? this->num_of_publications : 1) /
                                    std::log(10))
                              ];
    //Formed number of all publications
    sprintf(nop_out, "%s:\t%i",
                 "\nNumber of all publications", this->num_of_publications);
    //getting data from all publications and calulating their overall size
    char ** pubs_out = new char*[num_of_publications];
    int totalsize = 0;
    for (int i=0; i < this->num_of_publications; i++){
        *(pubs_out + i) = (*(this->publications + i))->out();
        totalsize += std::strlen(*(pubs_out + i));
    };
    //allocating resulting string, with size as sum of all pieces
    char * res = new char[sizeof "Customer information:\t" + (std::strlen(customer_out) + 1) +
                          sizeof "Signing date:\t" + (std::strlen(date_out) + 1) +
                          (std::strlen(nop_out) + 1) +
                          sizeof "\nList of all publications:\n" + totalsize + 
                          (sizeof "\t")*num_of_publications
                          ];
    //Collecting all strings in resulting string
    std::strcpy(res, "Customer information:\t");
    std::strcat(res, customer_out);
    std::strcat(res, "\nSigning date:\t");
    std::strcat(res, date_out);
    std::strcat(res, nop_out);
    std::strcat(res, "\nList of all publications:\n");
    for (int i=0; i < num_of_publications; i++){
        std::strcat(res, "\t");
        std::strcat(res, *(pubs_out + i));
    };
    //now it's time to deallocate these arrays
    delete[] customer_out;
    delete[] date_out;
    delete[] nop_out;
    for (int i=0; i < num_of_publications; i++){
        delete[] *(pubs_out + i);
    };
    delete [] pubs_out;
    return res;
};

Research& Research::addPublication(const Publication& in_publication){
    this->num_of_publications += 1;
    this->publications = (Publication**)std::realloc(this->publications, this->num_of_publications * sizeof (Publication*));
    *(this->publications + this->num_of_publications - 1) = new Publication(in_publication);
    return *this;
};

Research& Research::modCustomer(const Customer & in_customer){
    delete this->customer;
    this->customer = new Customer(in_customer);
    return *this;
};

//DESTRUCTOR RESEARCH
Research::~Research(){
    for (int i=0; i < num_of_publications; i++){
        delete *(this->publications + i);
    };
    std::free(this->publications);
    delete customer;
};
