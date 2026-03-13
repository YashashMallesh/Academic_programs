create user c##filename;
identified by password;
grant resource, connect to c##filename;
grant unlimited tablespace to c##filename;
grant create view to c##filename;
connect c##filename/password;

create table Emp(Empno number(3), Ename varchar(15), Job varchar(10), Mno(3), sal number(10,2));
insert into Emp values(1,'Job','Manager',NULL,5000);
insert into Emp valueS(2,'Smith','Dev',1,4000);
insert into Emp values(3,'Richard','CEO',NULL,5000);
select * from Emp;
desc Emp;
delete * from Emp;
rollback;
Select * from Emp;
commit;
delete * from Emp;
select * from Emp;
rollback;
select * from Emp;

DROP table Emp;

create table Emp(Empno number(3), Ename varchar(15), Job varchar(10), Mno(3), sal number(10,2));
alter table Emp add com decimal(10,2);
desc Emp;
insert into Emp values(1,'Job','Manager',2,5000,1000);
insert into Emp valueS(2,'Smith','Dev',1,4000,2000);
insert into Emp values(3,'Richard','CEO',3,5000,1000);
alter table Emp rename column mgr to mgrid;
desc Emp;
UPDATE Emp set job = 'ProjectMgr' where mgrid = 1;
delete from Emp where Empno = 105;
select * from Emp;
