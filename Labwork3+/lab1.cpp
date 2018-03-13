#include "lab1mod.hpp"
#include <iostream>
#undef max
#include <limits>


int main(){
        Date x = Date(11, 11, 1596), y = Date(1,1,1490), z;
        z = (x + y);
        std::cout<<z.out()<<std::endl;

        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        Customer cust ("Andrew", "Lol", 1500), cust2;
        Research r1, r2 = Research(cust, z);
        std::cout<<(r1<r2)<<std::endl;
        std::cout<<"----------------------------"<<std::endl;
        std::cout<<(r1>r2)<<std::endl;

        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<r2[0]<<std::endl;
        std::cout<<"----------------------------"<<std::endl;
        Student stud1 ("Alex", "Trump", 2014), stud2 ("Donald", "Trump", 2014);
        Publication pub (stud1, ARTICLE), pub2;
        r2.addPublication(pub);
        std::cout<<r2[0]<<std::endl;

        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<(stud1==stud2)<<" "<<(stud1!=stud2)<<std::endl;
        stud2.modName("Alex");
        std::cout<<"----------------------------"<<std::endl;
        std::cout<<(stud1==stud2)<<" "<<(stud1!=stud2)<<std::endl;
        
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<stud1;
        std::cout<<"----------------------------"<<std::endl;
        std::cin>>stud2;
        std::cout<<"----------------------------"<<std::endl;
        std::cout<<stud2;

        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<pub;
        std::cout<<"----------------------------"<<std::endl;
        std::cin>>pub;
        std::cout<<"----------------------------"<<std::endl;
        std::cout<<pub;

        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<stud1<<std::endl;
        stud1=stud2;
        std::cout<<stud1<<std::endl;

        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<cust2.out()<<std::endl;
        cust2=cust;
        std::cout<<cust2.out()<<std::endl;

        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<pub2<<std::endl;
        pub2=pub;
        std::cout<<pub2<<std::endl;

        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<r2.out()<<std::endl;
        std::cout<<"----------------------------"<<std::endl;
        std::cout<<r1.out()<<std::endl;
        std::cout<<"----------------------------"<<std::endl;
        r1=r2;
        std::cout<<r1.out()<<std::endl;

        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        //реализуем полиморфизм
        Customer custom_virt; 
        Research research_virt;       
        Customer* cust_v1 = &custom_virt;
        Customer* cust_v2 = &research_virt;
        std::cout<<cust_v1->out()<<std::endl;
        std::cout<<"----------------------------"<<std::endl;
        std::cout<<cust_v2->out()<<std::endl;
                  
        return 0;
};
