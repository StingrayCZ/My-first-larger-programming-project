# END-TO-END ENCRYPTION PROTOCOL FOR IEEE 802.15.4

This thesis explores the topic of encryption of communication between low-voltage devices that are controlled by microcontrollers. Two deRFnod development boards were used in the work, which were equipped with AVR ATmega 128 RFA1 chips, which enable wireless communication. The application was developed and tested on these devices. The final output of the work is the design of an application for asymmetric key exchange, which is based on elliptic curves. This application is implemented in Atmel LightWeight, where the issue of mutual communication between communicating points is also addressed.

There was a requirement to use large numbers, so I had to use a special lib for computing big numbers (e.g. 2^128). (See <a href="https://www.di-mgt.com.au/bigdigits.html"> here</a>)



(See document of my Thesis, click <a href="https://github.com/StingrayCZ/My-first-larger-programming-project-in-C/blob/master/THESIS%20BACA.pdf"> here</a>)

## Main Scheme

<p float="left">
  <img src="/Flowchart/Main Scheme.png" width="700" /> 
</p>  

## Summary of All Flowcharts

<p float="left">
  <img src="/Flowchart/All.png" width="800" /> 
</p>
(click <a href="https://github.com/StingrayCZ/My-first-larger-programming-project-in-C/blob/master/Flowchart%20(pdf)/All%20Flowcharts.pdf"> here</a> for better resolution)

</p>

Each application has in its header a description of the function and a list of inputs and outputs.

## PointCompBIGD

<p float="left">
  <img src="/Flowchart/1.png" width="500" /> 
</p>

(click <a href="https://github.com/StingrayCZ/My-first-larger-programming-project-in-C/blob/master/Source%20of%20Code/PointCompBig.c"> here</a> for better resolution)



