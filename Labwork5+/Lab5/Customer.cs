using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Customer:ICloneable
    {
        protected string name, theme;
        protected int price;
        public Customer(){
            Name = "Name";
            Theme = "Theme";
            Price = 0;
        }
        public Customer(string nam, string them, int pric){
            try{
                Name = String.Copy(nam);
                Theme = String.Copy(them);
                Price = pric;
            }
            catch{}
        }
        public object Clone(){
            return new Customer(Name, Theme, Price);
        }
        public string Name{get; set;}
        public string Theme{get; set;}
        public int Price{
            get{return price;} 
            set{if (value>0) price = value;}
        }
        public override string ToString()
        {
            return "\nName : " + name + "\nTheme : " + theme + "\nPrice : " + price.ToString();
        }
        public virtual void FullOut(){
            Console.WriteLine(ToString());
        }
        public void ShortOut(){
            Console.WriteLine("{0} {1}", Name, Price);
        }
    }
}
