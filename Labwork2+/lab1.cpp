#include "lab1mod.hpp"
#include <iostream>
#include <regex>

#define NUM_OF_OBJECTS 3 

//char to date
int* char2date(const char * in_string){
    std::regex date_regex = std::regex("^([[:digit:]]{1,2})\\.([[:digit:]]{1,2})\\.([[:digit:]]{1,4}$)");
    std::cmatch m;
    if (std::regex_search(in_string, m, date_regex)) {
        int * res = new int[3];
        for (int i=0; i < 3; i++)
            res[i] = std::atoi(m[i+1].str().c_str());
        return res;
    } else {
        std::cerr << "What's a pity, couldn't fit format." << std::endl;
        return NULL;
        };
};

int* return_date(char* oooh){
        return char2date(oooh);;       
}

int main(){
//    //create objects
//    Date* date_for_example;
//    Customer* customer_for_example;
//    Publication *publication_example;
//    Research* example[NUM_OF_OBJECTS]; //array of researches
//    char* res;

//    //enter date for research
//    std::cout << "Please enter date in day.month.year format and then press Enter." << std::endl;
//    char* buf = new char[8];
//    std::cin >> buf;
//    int* date_for_example_as_int = char2date(buf);
//    while (date_for_example_as_int == NULL){
//        std::cout << "Please enter date in day.month.year format and then press Enter." << std::endl;
//        std::cin >> buf;
//        date_for_example_as_int=return_date(buf);
//    }
//    delete buf;
//    //after input we check whether the date is valid
//    if (Date::verify(date_for_example_as_int)) {
//        date_for_example = new Date(*(date_for_example_as_int),
//                                           *(date_for_example_as_int + 1),
//                                           *(date_for_example_as_int + 2));
//        delete date_for_example_as_int;
//    } else {
//        std::cerr << "Sorry, date isn't valid... C u!" << std::endl;
//        delete date_for_example_as_int;
//        return 0;
//	 };

//    //enter customer data for research
//    char* name_buf = new char[80];
//    char* theme_buf = new char[80];
//    int price;
//    std::cout << "Please enter customer's name (ascii only, not more than 80 charachters)." << std::endl;
//    std::cin >> name_buf;
//    std::cout << "Please enter theme (ascii only, not more than 80 charachters) and then press Enter." << std::endl;
//    std::cin >> theme_buf;
//    std::cout << "Please enter price (int only) and then press Enter." << std::endl;
//    std::cin >> price;
//    customer_for_example = new Customer(name_buf, theme_buf, price);//cause in our case we declared customer_for_example as a pointer

//    example[0] = new Research(); //standart constructor(everything is predefined)
//    example[1] = new Research(*customer_for_example, *date_for_example);//our "input" constructor
//    example[2] = new Research(*example[1]);//constructor of copy
//    
//    //enter data for publication

//    for (int i=0; i < NUM_OF_OBJECTS-2; i++){
//        std::cout << "\n------------Example " << i+1 << "------------"<<std::endl;
//        
//        res = example[i]->getInfo();
//        std::cout <<"\nShort info:" << std::endl << res << std::endl ;
//        delete res;
//        char* surname_temp = new char[80];   
//        std::cout<<"\nInput student's surname: ";
//        std::cin>>surname_temp;
//        std::cout<<" "<<std::endl;;   
//        Student stud_example (name_buf, surname_temp, 2016);
//        publication_example = new Publication(stud_example, ARTICLE);
//        example[i]->addPublication( *publication_example);
//        res = example[i]->out();
//        std::cout << "\nFull-size out:" << std::endl << res << std::endl ;
//        res = example[i]->getInfo();
//        std::cout <<"\nShort info after adding a publication:" << std::endl << res << std::endl ;

//        delete example[i];
//        delete publication_example;
//    };
//    //delete example;
//    delete date_for_example;
//    delete customer_for_example;

        Research a;

    return 0;
};
