EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR06
U 1 1 5C096C52
P 2550 4950
F 0 "#PWR06" H 2550 4700 50  0001 C CNN
F 1 "GND" H 2555 4777 50  0000 C CNN
F 2 "" H 2550 4950 50  0001 C CNN
F 3 "" H 2550 4950 50  0001 C CNN
	1    2550 4950
	1    0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR08
U 1 1 5C096C65
P 2250 4950
F 0 "#PWR08" H 2250 4800 50  0001 C CNN
F 1 "+3.3V" H 2265 5123 50  0000 C CNN
F 2 "" H 2250 4950 50  0001 C CNN
F 3 "" H 2250 4950 50  0001 C CNN
	1    2250 4950
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR09
U 1 1 5C0971FB
P 6150 5000
F 0 "#PWR09" H 6150 4850 50  0001 C CNN
F 1 "+3.3V" H 6165 5173 50  0000 C CNN
F 2 "" H 6150 5000 50  0001 C CNN
F 3 "" H 6150 5000 50  0001 C CNN
	1    6150 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5C097210
P 6250 5350
F 0 "#PWR07" H 6250 5100 50  0001 C CNN
F 1 "GND" H 6255 5177 50  0000 C CNN
F 2 "" H 6250 5350 50  0001 C CNN
F 3 "" H 6250 5350 50  0001 C CNN
	1    6250 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 5000 6150 5050
Wire Wire Line
	6150 5050 6250 5050
Text GLabel 5400 4600 2    50   Input ~ 0
RX
Text GLabel 5400 4800 2    50   Output ~ 0
TX
Text GLabel 5400 5400 2    50   Output ~ 0
CTS
Text GLabel 6250 5250 0    50   Output ~ 0
TX
Text GLabel 6250 5150 0    50   Input ~ 0
RX
Text GLabel 6200 5850 0    50   Output ~ 0
CTS
Text GLabel 3400 4700 0    50   Output ~ 0
BLUE0
Text GLabel 3400 4900 0    50   Output ~ 0
RED0
Text GLabel 3900 4100 1    50   Output ~ 0
GREEN1
Text GLabel 4100 4100 1    50   Output ~ 0
RED1
Text GLabel 4850 2900 3    50   Input ~ 0
GREEN1
$Comp
L power:GND #PWR02
U 1 1 603CCDE5
P 3400 6000
F 0 "#PWR02" H 3400 5750 50  0001 C CNN
F 1 "GND" H 3405 5827 50  0000 C CNN
F 2 "" H 3400 6000 50  0001 C CNN
F 3 "" H 3400 6000 50  0001 C CNN
	1    3400 6000
	1    0    0    -1  
$EndComp
Text GLabel 3750 2900 3    50   Input ~ 0
RED0
Text GLabel 4300 4100 1    50   Output ~ 0
BLUE1
Text GLabel 4500 4100 1    50   Input ~ 0
SW0
$Comp
L power:+3.3V #PWR01
U 1 1 603D8547
P 5050 3800
F 0 "#PWR01" H 5050 3650 50  0001 C CNN
F 1 "+3.3V" V 4950 3800 50  0000 C CNN
F 2 "" H 5050 3800 50  0001 C CNN
F 3 "" H 5050 3800 50  0001 C CNN
	1    5050 3800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 603DFA5E
P 5400 5600
F 0 "#PWR0101" H 5400 5350 50  0001 C CNN
F 1 "GND" H 5405 5427 50  0000 C CNN
F 2 "" H 5400 5600 50  0001 C CNN
F 3 "" H 5400 5600 50  0001 C CNN
	1    5400 5600
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 603E6853
P 2250 4950
F 0 "#FLG0101" H 2250 5025 50  0001 C CNN
F 1 "PWR_FLAG" V 2250 5078 50  0001 L CNN
F 2 "" H 2250 4950 50  0001 C CNN
F 3 "~" H 2250 4950 50  0001 C CNN
	1    2250 4950
	0    -1   1    0   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 603E942F
P 2550 4950
F 0 "#FLG0102" H 2550 5025 50  0001 C CNN
F 1 "PWR_FLAG" V 2550 5077 50  0001 L CNN
F 2 "" H 2550 4950 50  0001 C CNN
F 3 "~" H 2550 4950 50  0001 C CNN
	1    2550 4950
	0    1    -1   0   
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 6041C4DE
P 4300 1400
F 0 "BT1" H 4418 1496 50  0000 L CNN
F 1 "Battery_Cell" H 4418 1405 50  0000 L CNN
F 2 "Battery:BatteryHolder_MPD_BC2003_1x2032" V 4300 1460 50  0001 C CNN
F 3 "~" V 4300 1460 50  0001 C CNN
	1    4300 1400
	0    1    1    0   
$EndComp
$Comp
L _AZ:az_BL652 U1
U 1 1 6042AA22
P 4400 5200
F 0 "U1" H 4400 4225 50  0000 C CNN
F 1 "az_BL652" H 4400 4134 50  0000 C CNN
F 2 "RF_Module:Laird_BL652" H 4400 4000 50  0001 C CNN
F 3 "http://cdn.lairdtech.com/home/brandworld/files/Datasheet%20-%20BL652.pdf" H 4400 3900 50  0001 C CNN
	1    4400 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 5600 3400 5600
Wire Wire Line
	2050 5500 3400 5500
$Comp
L power:GND #PWR013
U 1 1 6044A396
P 5050 4100
F 0 "#PWR013" H 5050 3850 50  0001 C CNN
F 1 "GND" V 5050 3900 50  0000 C CNN
F 2 "" H 5050 4100 50  0001 C CNN
F 3 "" H 5050 4100 50  0001 C CNN
	1    5050 4100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 6044DE65
P 3200 4500
F 0 "#PWR04" H 3200 4250 50  0001 C CNN
F 1 "GND" H 3205 4327 50  0000 C CNN
F 2 "" H 3200 4500 50  0001 C CNN
F 3 "" H 3200 4500 50  0001 C CNN
	1    3200 4500
	-1   0    0    1   
$EndComp
Text GLabel 5400 5200 2    50   Output ~ 0
RTS
Text GLabel 6200 5700 0    50   Input ~ 0
RTS
Wire Wire Line
	4900 4100 5050 4100
Text GLabel 3400 5100 0    50   Output ~ 0
GREEN0
Text GLabel 5250 2900 3    50   Input ~ 0
BLUE1
Text GLabel 5050 2900 3    50   Input ~ 0
RED1
$Comp
L power:GND #PWR010
U 1 1 6045B5DA
P 4200 1400
F 0 "#PWR010" H 4200 1150 50  0001 C CNN
F 1 "GND" H 4205 1227 50  0000 C CNN
F 2 "" H 4200 1400 50  0001 C CNN
F 3 "" H 4200 1400 50  0001 C CNN
	1    4200 1400
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR011
U 1 1 6045BF91
P 4500 1400
F 0 "#PWR011" H 4500 1250 50  0001 C CNN
F 1 "+3.3V" H 4515 1573 50  0000 C CNN
F 2 "" H 4500 1400 50  0001 C CNN
F 3 "" H 4500 1400 50  0001 C CNN
	1    4500 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	3400 4500 3200 4500
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 6045EA40
P 3850 3400
F 0 "J1" H 3930 3392 50  0000 L CNN
F 1 "Conn_01x02" H 3930 3301 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 3850 3400 50  0001 C CNN
F 3 "~" H 3850 3400 50  0001 C CNN
	1    3850 3400
	1    0    0    -1  
$EndComp
Text GLabel 3650 3400 0    50   Input ~ 0
SW0
$Comp
L power:GND #PWR05
U 1 1 6046196A
P 3650 3500
F 0 "#PWR05" H 3650 3250 50  0001 C CNN
F 1 "GND" H 3655 3327 50  0000 C CNN
F 2 "" H 3650 3500 50  0001 C CNN
F 3 "" H 3650 3500 50  0001 C CNN
	1    3650 3500
	1    0    0    -1  
$EndComp
NoConn ~ 3400 4600
NoConn ~ 3400 4800
NoConn ~ 3400 5000
NoConn ~ 3400 5200
NoConn ~ 3400 5700
NoConn ~ 3400 5800
NoConn ~ 3400 5900
NoConn ~ 5400 5500
NoConn ~ 5400 5300
NoConn ~ 5400 5100
NoConn ~ 5400 4900
NoConn ~ 5400 4700
NoConn ~ 5400 4500
$Comp
L Device:C C1
U 1 1 604678FD
P 5050 3950
F 0 "C1" H 5165 3996 50  0000 L CNN
F 1 "C" H 5165 3905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5088 3800 50  0001 C CNN
F 3 "~" H 5050 3950 50  0001 C CNN
	1    5050 3950
	1    0    0    -1  
$EndComp
Connection ~ 5050 4100
Wire Wire Line
	4800 4100 4800 3800
Wire Wire Line
	4800 3800 5050 3800
Connection ~ 5050 3800
NoConn ~ 4000 4100
NoConn ~ 4200 4100
NoConn ~ 4400 4100
NoConn ~ 4600 4100
NoConn ~ 4700 4100
$Comp
L _AZ:LED_RGB_5050 D2
U 1 1 60437609
P 3750 2500
F 0 "D2" V 3704 2860 50  0000 L CNN
F 1 "LED_RGB_5050" V 3795 2860 50  0000 L CNN
F 2 "LED_SMD:LED_RGB_5050-6" H 3750 2450 50  0001 C CNN
F 3 "~" H 3750 2450 50  0001 C CNN
	1    3750 2500
	0    -1   -1   0   
$EndComp
$Comp
L _AZ:LED_RGB_5050 D3
U 1 1 604447A5
P 5050 2500
F 0 "D3" V 5004 2860 50  0000 L CNN
F 1 "LED_RGB_5050" V 5095 2860 50  0000 L CNN
F 2 "LED_SMD:LED_RGB_5050-6" H 5050 2450 50  0001 C CNN
F 3 "~" H 5050 2450 50  0001 C CNN
	1    5050 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3550 2300 3550 2150
Wire Wire Line
	3550 2150 3750 2150
Wire Wire Line
	3750 2150 3750 2050
Wire Wire Line
	3750 2300 3750 2150
Connection ~ 3750 2150
Wire Wire Line
	3950 2300 3950 2150
Wire Wire Line
	3950 2150 3750 2150
Wire Wire Line
	4850 2300 4850 2150
Wire Wire Line
	4850 2150 5050 2150
Wire Wire Line
	5050 2150 5050 2050
Wire Wire Line
	5050 2300 5050 2150
Connection ~ 5050 2150
Wire Wire Line
	5250 2300 5250 2150
Wire Wire Line
	5250 2150 5050 2150
Wire Wire Line
	2250 4950 2250 5200
Wire Wire Line
	2250 5200 2050 5200
Connection ~ 2250 4950
NoConn ~ 3400 5400
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 6045B738
P 6450 5150
F 0 "J2" H 6530 5142 50  0000 L CNN
F 1 "Conn_01x04" H 6530 5051 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 6450 5150 50  0001 C CNN
F 3 "~" H 6450 5150 50  0001 C CNN
	1    6450 5150
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP4
U 1 1 6045D3B0
P 6200 5850
F 0 "TP4" V 6154 6038 50  0000 L CNN
F 1 "TestPoint" V 6245 6038 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.0x1.0mm" H 6400 5850 50  0001 C CNN
F 3 "~" H 6400 5850 50  0001 C CNN
	1    6200 5850
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP3
U 1 1 6045E3B6
P 6200 5700
F 0 "TP3" V 6154 5888 50  0000 L CNN
F 1 "TestPoint" V 6245 5888 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.0x1.0mm" H 6400 5700 50  0001 C CNN
F 3 "~" H 6400 5700 50  0001 C CNN
	1    6200 5700
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP2
U 1 1 6045E930
P 5400 5000
F 0 "TP2" V 5354 5188 50  0000 L CNN
F 1 "TestPoint" V 5445 5188 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.0x1.0mm" H 5600 5000 50  0001 C CNN
F 3 "~" H 5600 5000 50  0001 C CNN
	1    5400 5000
	0    1    1    0   
$EndComp
NoConn ~ 3400 5300
$Comp
L Device:C C2
U 1 1 60484810
P 2400 4950
F 0 "C2" H 2515 4996 50  0000 L CNN
F 1 "C" H 2515 4905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2438 4800 50  0001 C CNN
F 3 "~" H 2400 4950 50  0001 C CNN
	1    2400 4950
	0    1    1    0   
$EndComp
Connection ~ 2550 4950
Wire Wire Line
	2550 5300 2550 4950
Wire Wire Line
	2050 5300 2550 5300
$Comp
L Device:R_Small R1
U 1 1 60493226
P 3550 2800
F 0 "R1" V 3450 2800 50  0000 L CNN
F 1 "330" V 3450 2650 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3550 2800 50  0001 C CNN
F 3 "~" H 3550 2800 50  0001 C CNN
	1    3550 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
U 1 1 60493EBF
P 3750 2800
F 0 "R2" V 3650 2800 50  0000 L CNN
F 1 "330" V 3650 2650 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3750 2800 50  0001 C CNN
F 3 "~" H 3750 2800 50  0001 C CNN
	1    3750 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R3
U 1 1 604941FC
P 3950 2800
F 0 "R3" V 3850 2800 50  0000 L CNN
F 1 "330" V 3850 2650 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3950 2800 50  0001 C CNN
F 3 "~" H 3950 2800 50  0001 C CNN
	1    3950 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R4
U 1 1 6049455D
P 4850 2800
F 0 "R4" V 4750 2800 50  0000 L CNN
F 1 "330" V 4750 2650 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4850 2800 50  0001 C CNN
F 3 "~" H 4850 2800 50  0001 C CNN
	1    4850 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R5
U 1 1 60494C03
P 5050 2800
F 0 "R5" V 4950 2800 50  0000 L CNN
F 1 "330" V 4950 2650 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5050 2800 50  0001 C CNN
F 3 "~" H 5050 2800 50  0001 C CNN
	1    5050 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R6
U 1 1 60494EA7
P 5250 2800
F 0 "R6" V 5150 2800 50  0000 L CNN
F 1 "330" V 5150 2650 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5250 2800 50  0001 C CNN
F 3 "~" H 5250 2800 50  0001 C CNN
	1    5250 2800
	1    0    0    -1  
$EndComp
Text GLabel 3950 2900 3    50   Input ~ 0
BLUE0
Text GLabel 3550 2900 3    50   Input ~ 0
GREEN0
$Comp
L Connector_Generic:Conn_01x06 J3
U 1 1 604DE809
P 1850 5300
F 0 "J3" H 1768 5717 50  0000 C CNN
F 1 "Conn_01x06" H 1768 5626 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 1850 5300 50  0001 C CNN
F 3 "~" H 1850 5300 50  0001 C CNN
	1    1850 5300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2050 5200 2050 5100
Connection ~ 2050 5200
NoConn ~ 2050 5400
$Comp
L power:+3.3V #PWR0102
U 1 1 6050524D
P 5050 2050
F 0 "#PWR0102" H 5050 1900 50  0001 C CNN
F 1 "+3.3V" H 5065 2223 50  0000 C CNN
F 2 "" H 5050 2050 50  0001 C CNN
F 3 "" H 5050 2050 50  0001 C CNN
	1    5050 2050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0103
U 1 1 60505B98
P 3750 2050
F 0 "#PWR0103" H 3750 1900 50  0001 C CNN
F 1 "+3.3V" H 3765 2223 50  0000 C CNN
F 2 "" H 3750 2050 50  0001 C CNN
F 3 "" H 3750 2050 50  0001 C CNN
	1    3750 2050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
