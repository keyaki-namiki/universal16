EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr User 5906 4331
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
L Connector_Generic:Conn_01x01 J1
U 1 1 5C619809
P 2800 1400
F 0 "J1" H 2880 1442 50  0000 L CNN
F 1 "Conn_01x01" H 2880 1351 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 2800 1400 50  0001 C CNN
F 3 "~" H 2800 1400 50  0001 C CNN
	1    2800 1400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J2
U 1 1 5C619873
P 2800 1600
F 0 "J2" H 2880 1642 50  0000 L CNN
F 1 "Conn_01x01" H 2880 1551 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 2800 1600 50  0001 C CNN
F 3 "~" H 2800 1600 50  0001 C CNN
	1    2800 1600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 5C61988B
P 2800 1800
F 0 "J3" H 2880 1842 50  0000 L CNN
F 1 "Conn_01x01" H 2880 1751 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 2800 1800 50  0001 C CNN
F 3 "~" H 2800 1800 50  0001 C CNN
	1    2800 1800
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 5C6198A5
P 2800 2000
F 0 "J4" H 2880 2042 50  0000 L CNN
F 1 "Conn_01x01" H 2880 1951 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 2800 2000 50  0001 C CNN
F 3 "~" H 2800 2000 50  0001 C CNN
	1    2800 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1400 2600 1600
Connection ~ 2600 1600
Wire Wire Line
	2600 1600 2600 1800
Connection ~ 2600 1800
Wire Wire Line
	2600 1800 2600 2000
$EndSCHEMATC
