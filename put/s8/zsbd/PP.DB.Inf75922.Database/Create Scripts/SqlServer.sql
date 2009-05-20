create table books (
	book_id numeric(10) primary key,
	title nvarchar(400) not null
);
 
create table users (
	pesel nvarchar(11) primary key,
	name nvarchar(50) not null,
	surname nvarchar(50) not null
);

create table rented_books (
	rented_book numeric(10) references books(book_id),
	users_pesel nvarchar(11) references users(pesel),
	primary key(rented_book, users_pesel)
);
