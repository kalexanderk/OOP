using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Research:Customer, ICloneable, IComparable
    {
        private DateTime sign_date;
        private Publication[] publications;
        private int num_of_publications;
        public DateTime Sign_date{get; set; }
        public Publication[] Publications{
            get{return publications;}
            set{if (value is Publication[]) publications = (Publication[])value;}
        }
        public int Num_of_publications{
            get{return num_of_publications;}
            set{if (value>0) num_of_publications = value;}
        }

        public Research():base(){
            Sign_date=DateTime.Today;
            Num_of_publications = 0;
            this.publications = new Publication[1];
        }
        public Research(Customer cust, Publication[] pubs):base(cust.Name, cust.Theme, cust.Price){
            Sign_date = DateTime.Today;
            if (pubs != null && pubs.Length != 0)
            {
                Num_of_publications = pubs.Length;
                publications = new Publication[Num_of_publications];
                for (int i = 0; i < Num_of_publications; i++) publications[i] = (Publication)pubs[i].Clone();
            }
            else
            {
                Num_of_publications = 0;
                this.publications = new Publication[1];
            }
        }
        public new object Clone(){
            Publication[] temp = new Publication[this.Num_of_publications];
            for (int i = 0; i < this.Num_of_publications; i++) temp[i] = (Publication)this.publications[i].Clone();
            return new Research(new Customer(Name, Theme, Price), temp);
        }

        public void AddPublication(Publication pub){
            int oldsize = Num_of_publications;
            if (oldsize > 0)
            {
                Publication[] temp = new Publication[oldsize];
                for (int i = 0; i < oldsize; i++) temp[i] = publications[i];
                publications = new Publication[oldsize + 1];
                for (int i = 0; i < oldsize; i++) publications[i] = temp[i];
                publications[oldsize] = pub;
            }
            else
            {
                publications = new Publication[1];
                publications[oldsize] = pub;

            }
            Num_of_publications = publications.Length;
        }

        public int CompareTo(object o)
        {
            if(o != null && o is Research){
                Research temp = (Research)o;
                if (Price < temp.Price) return -1;
                if (Price > temp.Price) return 1;
                return 0;
            }
            else throw new ArgumentException("Error in CompareTo.");
        }
        public static bool operator>(Research lhs, Research rhs){
            return (lhs.CompareTo(rhs)>0 | lhs.CompareTo(rhs)==0);
        }
        public static bool operator<(Research lhs, Research rhs){
            return lhs.CompareTo(rhs)<0;
        }

        public string this[int index]{
            get{ return publications[index].ToString();}
            set{Console.WriteLine("Impossible to write string to Publication.");}
        }

        public override string ToString()
        {
            string temp = "\nName : " + Name + "\nPrice : " + Price.ToString() + "\nResearch date : " + Sign_date.ToString()
                + "\nTheme of research : " + Theme + "\nNumber of publications : " + Num_of_publications.ToString();
            for (int i = 0; i < Num_of_publications; i++) temp += publications[i].ToString();
            return temp;
        }
        public override void FullOut()
        {
            Console.WriteLine(ToString());
        }

        public new void ShortOut()
        {
            Console.WriteLine("Number of publications : {0}", Num_of_publications);
        }

    }
}
