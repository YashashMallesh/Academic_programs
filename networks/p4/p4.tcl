set ns [new Simulator] 
set nf [open p4.nam w] 
$ns namtrace-all $nf 
set nd [open p4.tr w] 
$ns trace-all $nf
proc finish { } {
global ns nf nd
$ns flush-trace 
close $nf
close $nf
exec nam p4.nam &
exit 0
}
