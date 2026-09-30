set ns [new Simulator] 
set nf [open p1.nam w] 
$ns namtrace-all $nf 
set nd [open p1.tr w] 
$ns trace-all $nf
proc finish { } {
global ns nf nd
$ns flush-trace 
close $nf
close $nf
exec nam p1.nam &
exit 0
}
set n0 [$ns node] 
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
