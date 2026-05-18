create view Emp_project as
select EMP.name, PROJECT.name
from EMP as E, WORKS_ON as W, PROJECT as P
where E.ssn = W.ssn and
      E.Pno = P.Pnumber;
