using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    public enum SciAchivment { THESIS, ARTICLE, REPORT, INTARTICLE };

    class Program
    {
        static void Main(string[] args)
        {
            
            Student stud1 = new Student("Devi", "Jones", 1678);
            Student stud2 = stud1.Clone() as Student;
            Console.WriteLine("Student 1: {0}\n", stud1);
            Console.WriteLine("Student 2: {0}\n", stud2);
            Console.WriteLine("Student 1==Student 2: {0}\n", stud1==stud2);
            stud2.Enroll_year = 1976;
            Console.WriteLine("Student 1==Student 2: {0}\n", stud1 == stud2);
            Console.WriteLine("\n------------------");

            Customer cust1 = new Customer("Yanina", "Religion", 115);
            Publication pub1 = new Publication(stud1, SciAchivment.ARTICLE);
            Publication[] pubarray = new Publication[3];
            pubarray[0]=new Publication();
            pubarray[1]=new Publication();
            pubarray[2] = (Publication)pub1.Clone();

            Research ob1 = new Research(cust1, null);
            Research ob2 = ob1.Clone() as Research;
            Console.WriteLine("Research 1: {0}\n", ob1);
            Console.WriteLine("\n------------------");
            ob2.AddPublication(pub1);
            Console.WriteLine("Research 2: {0}\n", ob2);
            Customer ob3 = new Research(cust1, pubarray);
            Console.WriteLine("Research 3: {0}\n", ob3);
            Console.WriteLine("\n------------------");
            Console.WriteLine("Research 3 < Research 2: {0}\n", ob2<ob1);
            Console.WriteLine("\n------------------");

            Console.WriteLine(ob2[0]);
            Console.WriteLine("\n------------------");

            cust1.FullOut();
            Console.WriteLine("\n------------------");
            cust1.ShortOut();
            Console.WriteLine("\n------------------");
            ob3.FullOut();
            Console.WriteLine("\n------------------");
            ob3.ShortOut();
            Console.WriteLine("\n------------------");

            Console.ReadKey();
        }
    }
}
