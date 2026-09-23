BEGIN{
sent = 0;
recieved = 0;
dropped = 0;
}
{
event = $1;
if(event == "t"){
sent++;
}
if(event == "r"){
recieved++;
}
if(event == "d"){
dropped++;
}
}
END{
pdr = (recieved/sent)*100;
print"Number of packets sent = ",sent;
print"Number of packets recieved = ",recieved;
print"Number of packets dropped = ",dropped;
if(sent>0){
print"Packets drop ratio = ",pdr;
}
}
