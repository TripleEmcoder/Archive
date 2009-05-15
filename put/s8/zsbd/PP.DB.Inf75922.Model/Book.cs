using System.Collections.Generic;

namespace PP.DB.Inf75922.Model
{
    public class Book
    {
        public virtual int Id { get; set; }
        public virtual string Title { get; set; }
        public virtual ICollection<User> Users { get; set; }

        public Book()
        {
            Users = new List<User>();
        }
    }
}
