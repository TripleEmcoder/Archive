create table books (
	book_id number(10) primary key,
	title varchar2(400) not null
);
 
create table users (
	pesel varchar2(11) primary key,
	name varchar2(50) not null,
	surname varchar2(50) not null
);

create table rented_books (
	rented_book number(10) references books(book_id),
	users_pesel varchar2(11) references users(pesel),
	primary key(rented_book, users_pesel)
);
