BEGIN{
drop = 0;
}
{
if($1 == "d"){
  drop++;
  proto = $5;
}
}
END{
printf("Total No.of %s dropped due to congestion is = %d\n",proto,drop);
}
