#!/bin/bash

<<Docu
Name:
Date:
Assignment no. & Title:
Description:
Sample I/P:
Sample O/P:
Docu

echo "Perimeter of Recatngle"
read -p "Enter length:" len

read -p "Enter breadth:" bre
let peri=(2*($len+$bre))
echo perimeter of Rectange is: $peri
