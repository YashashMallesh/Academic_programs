set ns [new Simulator] 
set nf [open p2.nam w] 
$ns namtrace-all $nf 
set nd [open p2.tr w] 
$ns trace-all $nf
proc finish { } {
global ns nf nd
$ns flush-trace 
close $nf
close $nf
exec nam p2.nam &
exit 0
}
set n0 [$ns node] 
set n2 [$ns node]
$ns duplex-link $n0 $n2 1Mb 10ms DropTail 
set udp0 [new Agent/UDP] 
$ns attach-agent $n0 $udp0
set cbr0 [new Application/Traffic/CBR] 
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0
set sink [new Agent] 
$ns attach-agent $n3 $sink
$ns connect $udp0 $sink
$ns at 0.2 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run
