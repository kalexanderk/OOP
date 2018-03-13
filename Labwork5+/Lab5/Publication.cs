using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Publication:ICloneable
    {
        private Student author;
        private SciAchivment pub_type;
        public Student Author{
            get{return author;}
            set{if (value is Student) author=value;}
        }
        public SciAchivment Pub_type{get; set;}
        public Publication(){
            Author = new Student();
            Pub_type = (int)SciAchivment.THESIS;
        }
        public Publication(Student stu, SciAchivment ach){
            Author=(Student)stu.Clone();
            pub_type=ach;
        }
        public object Clone(){
            return new Publication(Author, Pub_type);
        }
        public override string ToString()
        {
            return "\nAuthor : " + author.ToString()+ "\nPublication type : " + pub_type.ToString();
        }
        public virtual void FullOut()
        {
            Console.WriteLine(ToString());
        }
        public void ShortOut()
        {
            Console.WriteLine("{0}", Pub_type);
        }
    }
}
