using System.Collections.Generic;

namespace PP.DB.Inf75922.Model
{
    public class Book
    {
        public virtual int Id { get; set; }
        public virtual string Title { get; set; }
        public virtual IList<User> Users { get; set; }
    }
}
