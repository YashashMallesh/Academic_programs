create table N_RollCall(
int id,
name varachar(10),
roll int
  );
desc N_RollCall;

create table O_RollCall(
  int id,
  name varchar(10),
  roll int
);
desc O_RollCall;
insert into N_RollCall values(1121,"Satya123",111);
insert into N_RollCall values(1121,"Satya123",111);
insert into N_RollCall values(1121,"Satya123",111);
insert into N_RollCall values(1121,"Satya123",111);
declare
v_count number;
cursor c_new_rollcall is
select id,name,roll
from n_rollcall;
begin
for new_rec in c_new_rollcall loop

select count(*)
into v_count
from o_rollcall
where id = new_rec.id;

if v_count = 0 then 
insert into o_rollcall(id,name,roll)
values(new_rec.id,new_rec.name,new_rec.roll);
dbms_output.put_line();
else
dbms_output.put_line();
end if;
end loop;
commit;
end;
/
select * from O_RollCall;
select * from N_RollCall;
commit;
