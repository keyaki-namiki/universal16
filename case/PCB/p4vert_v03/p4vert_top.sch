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
U 1 1 5C62F747
P 2800 1350
F 0 "J1" H 2880 1392 50  0000 L CNN
F 1 "Conn_01x01" H 2880 1301 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 2800 1350 50  0001 C CNN
F 3 "~" H 2800 1350 50  0001 C CNN
	1    2800 1350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J2
U 1 1 5C62F793
P 2800 1550
F 0 "J2" H 2880 1592 50  0000 L CNN
F 1 "Conn_01x01" H 2880 1501 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 2800 1550 50  0001 C CNN
F 3 "~" H 2800 1550 50  0001 C CNN
	1    2800 1550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 5C62F7AB
P 2800 1750
F 0 "J3" H 2880 1792 50  0000 L CNN
F 1 "Conn_01x01" H 2880 1701 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 2800 1750 50  0001 C CNN
F 3 "~" H 2800 1750 50  0001 C CNN
	1    2800 1750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 5C62F7C5
P 2800 1950
F 0 "J4" H 2880 1992 50  0000 L CNN
F 1 "Conn_01x01" H 2880 1901 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 2800 1950 50  0001 C CNN
F 3 "~" H 2800 1950 50  0001 C CNN
	1    2800 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1350 2600 1550
Connection ~ 2600 1550
Wire Wire Line
	2600 1550 2600 1750
Connection ~ 2600 1750
Wire Wire Line
	2600 1750 2600 1950
$EndSCHEMATC
