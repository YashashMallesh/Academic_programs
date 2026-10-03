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

$n4 shape box

$ns duplex-link $n0 $n4 100Mb 1ms DropTail
$ns duplex-link $n1 $n4 50Mb 1ms DropTail
$ns duplex-link $n2 $n4 2000Mb 1ms DropTail
$ns duplex-link $n3 $n4 200Mb 1ms DropTail
$ns duplex-link $n4 $n5 1Mb 1ms DropTail

set p1 [new Agent/Ping]
$ns attach-agent $n0 $p1
$p1 set packetSize_50000
$p1 set interval_0.0001

set p2 [new Agent/Ping]
$ns attach-agent $n1 $p2

set p3 [new Agent/Ping]
$ns attach-agent $n2 $p3
$p1 set packetSize_30000
$p1 set interval_0.00001

set p4 [new Agent/Ping]
$ns attach-agent $n3 $p4

set p5 [new Agent/Ping]
$ns attach-agent $n5 $p5

$ns queue-limit $n0 $n4 5
$ns queue-limit $n2 $n4 3
$ns queue-limit $n4 $n5 2

Agent/Ping instproc recv {from rtt}{
$self instvar node_
puts "node [$node_id] recieved answer from $from with round trip time $rtt msec"
}

$ns connect $p1 $p5
$ns connect $p3 $p4

proc finish {}{
global ns nf tf
$ns flush-trace
close $nf
close $tf
exec nam p3.nam &
exit 0
}

for {set t 0.1} {$t <= 2.9} {set t [expr {$t + 0.1}]} {
$ns at $t "$p1 send"
}
for {set t 0.1} {$1 <= 2.9} {set t [expr {$t + 0.1}]} {
$ns at $t "$p3 send"
}

$ns at 3.0 "finish"
$ns run
