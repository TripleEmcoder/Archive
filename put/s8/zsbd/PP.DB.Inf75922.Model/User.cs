using System.Collections.Generic;

namespace PP.DB.Inf75922.Model
{
    public class User
    {
        public virtual string Pesel { get; set; }
        public virtual string Name { get; set; }
        public virtual string Surname { get; set; }
        public virtual IList<Book> Books { get; set; }
    }
}
