using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Student:ICloneable
    {
        private string name, surname;
        private int enroll_year;
        public string Name {get; set;}
        public string Surname {get; set;}
        public int Enroll_year {
            get{return enroll_year;} 
            set{if (value>1000 & value<DateTime.Today.Year) enroll_year=value;}
        }
        public Student(){
            Name = "Name";
            Surname = "Surname";
            Enroll_year = DateTime.Today.Year;
        }
        public Student(string nam, string surnam, int year){
            try{
                Name = String.Copy(nam);
                Surname = String.Copy(surnam);
                Enroll_year=year;
            }
            catch{}     
        }
        public object Clone(){
            return new Student(this.Name, this.Surname, this.Enroll_year);
        }
        public override bool Equals(object o)
        {
            if (o != null && o is Student)
            {
                Student temp = o as Student;
                return ((Name.Equals(temp.Name)) & (Surname.Equals(temp.Surname)) & (Enroll_year == temp.Enroll_year));
            } 
            else {
                throw new ArgumentException("Error in Equals.");
            }
        }
        public override int GetHashCode()
        {
            //returns any one HashCode
            return (enroll_year.GetHashCode() | name.GetHashCode() | surname.GetHashCode() );
        }
        public static bool operator==(Student stud1, Student stud2){
            return stud1.Equals(stud2);
        }
        public static bool operator!=(Student stud1, Student stud2){
            return !stud1.Equals(stud2);
        }
        public void ShortOut() {
            Console.WriteLine("{0} {1}", Surname, Enroll_year);
        }
        public override string ToString(){ 
            return "\nName : " + Name + "\nSurname : " + Surname + "\nEnroll year : " + Enroll_year.ToString(); 
        }
        public void FullOut()
        {
            Console.WriteLine(ToString());
        }
    }
}
