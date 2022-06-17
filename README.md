# Gesture Recognition Glove

## Task Analysis and Statement of Problem

Communication is of significant importance in today’s data driven society, not only in extreme
situations, but also everyday life. Shopping at a supermarket, or asking for directions, event planning, or
even national security depend on reliable communication. To use certain public services, such as the
doctor’s office or local government, one could hire an interpreter to alleviate some of the frustration and
confusion of the communication barrier; however, hiring an interpreter can be expensive and time
consuming. Hearing-impaired people must face the challenges associated with the inability to
communicate verbally, which hinders their interaction with the rest of the hearing world. To use certain
public services, such as the doctor’s office or local government, one could hire an interpreter to alleviate
some of the frustration and confusion of the communication barrier; however, hiring an interpreter can
be expensive and time consuming. Despite such a large population of people who speak ASL, there are
few people outside of native speakers who can understand the language, which makes the challenge of
bridging the communication gap difficult. This project is an initiative to create a prototype device as a
proposed solution to this issue and to bridge the communication gap difficulty. It will explore the use of
a glove to provide sign-language translation in a way that improves on the methods of pre-existing
designs.

***The whole prototype will require 5 flex sensors, a development board, an accelerometer,
gyroscope, and a battery shield.*** During the making of this prototype, a wearable glove will be created
that is **responsive, portable, and durable.** It will be able to translate sign language gestures into readable
form for hearing-impaired people by analysing the bend of the fingers and the position of the hand in
space, process it and send messages to the website. The project started by selecting a suitable
development board, a suitable power supply corresponding the voltage input of this controller, selecting
the right sensors, developing the firmware, designing the PCB and enclosure, and building the prototype.
The PCB will rest along with the battery shield onto a custom-made enclosure. This enclosure will rest
on the back of the hand of the user using a strap keep it tight with the hand and a buckle connecting both
ends of the strap. It will have two straps going on the specified holes. One will be resting above the
thumb and the other strap that connects with a buckle, on the wrist. This will lead for the entire prototype
to not be too close to the fingers, making it a suitable place to make the connection through the
connectors.

The focus of the demo prototype will be on reading and analysing hand movement. Since ASL’s gestures require an extensive range of motions, including rotation and complex arm movement, the algorithm of this prototype will have to be exceptionally well written. It will need to capture correct and consistent analog to digital data to have a precise definition for each value. To bring the proposed design as close as possible to becoming a viable product, there should be a certain required level of standards related to safety to follow. As with any electronic equipment, there is a risk of shorting wires, which can result in injury or fire. This means the points where wires are connected with the Flex Sensors will be fully insulated and the enclosure will have to cover most of the PCB and power supply. Sometimes between gestures, there are very subtle differences and minor changes, so this similarity can be read and
analysed from the glove as the same gesture. The complexity of ASL make it challenging to distinguish
and capture differences between gestures. This means the sensors should have a desired sensitivity and
linearity as well as a well-developed software algorithm that detects these subtle changes. In this case,
we were faced with two options on how to proceed and develop the algorithm. One could be using
machine learning, where the glove would be trained over time by performing the same gestures, or by
creating a dataset function holding if constraints with segments of values. With datasets one gesture
would have exact predetermined values for every sensor reading and would be true if those values would
be met. Deciding which method to choose, and what components to use, we had to make several research
on similar products done beforehand and learn from them.

## Block Diagram

Our next very important step would be to design the block diagram, which will be crucial in the
foundation to the realization of this prototype. The block diagram provides a detailed view and
instructions, making it much easier to understand how every component is related to each other. It is
comprised of the Power supply, Input information, Data processing unit, Data acquisition and the
Website. Starting from the main source of power, the Power supply block (see figure below). It consists of
the battery which supplies the gyroscope, accelerometer, flex sensors and development board. The power
supply in our case will give a +5V as input voltage that goes into the voltage regulator of development
board which will drop it to 3.3V. We can see that the red line represents the input voltage throughout the
circuit. It goes from the microcontroller to the voltage divider of the flex sensor and to that sensor, and
it also connects with the accelerometer and gyroscope module.

Flex sensors will be connected with the microcontroller through an ADC pin and the
accelerometer and gyroscope through a I2C pin. The input information block is where the hand gestures
performed are picked up from the sensors as analog data and fed into the controller. This part only holds
outside factors regarding the prototype. The data given to the controller is processed and analysed
through the algorithm and checked with many datasets. Datasets in our case are going to be numerous if
constraints that hold specific values for when a certain sensor reaches that value. If one of these
constraints if fulfilled, then the output information, which is just a String value, will sent to the opened
webpage through the built-in Wi-Fi module of our development board. From the feeding of the data to
the microprocessor and till the moment this data was sent, it’s called Data Processing Block. In the last
stages of the block diagram, the data sent to webpage, arrives, gets pulled from a function in the
algorithm and is displayed.

The website will display the word, phrase, number, or letter depending on what gesture was
performed from the user of the glove. The information will be displayed as a translated gesture, which
is the goal of our prototype. To get access to this website, the user will have to be connected into the
same Wi-Fi that the board is connected to. By entering this local IP address into a browser of our choice,
we will be directed into the webpage, making the whole process of interaction, simple and efficient. The
website will be sending and giving requests with the board constantly.

![image](https://user-images.githubusercontent.com/66420672/174337449-ea25139d-c078-4aae-bba5-4b6928d0845c.png)

## Selection of Components

To achieve our desired goal and build our prototype, we had to decide which devices and
components to use. This meant researching for each main block in the block diagram to have a clearer
view on which device will be the most suitable for this project. Extensive research was conducted
especially for the development board since it will be the brains of this device.

### Development Board

Starting from the development board. Many were thought as possibilities for this project. Ideally,
we were looking for a board with a built-in Wi-Fi module, at least 5 analog pins, at least 1 I2C pin,
relatively fast clock speed (above 100 MHz), and enough flash memory so it can handle the algorithm,
opening a website, and sending the data to that website (above 2 MB). Three development boards that
stood out the most were Arduino UNO, ESP32 and Arduino Portenta. We will shortly go through the
main specifications regarding all three development boards and state our reasons for choosing the ESP32
as our main board.

#### ***Arduino UNO***

Arduino UNO is a microcontroller board based on the ATmega328P. This board has 14
input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs, a 16 MHz ceramic
resonator, a USB connection, a power jack, an ICSP header and a reset button. It contains everything
needed to support the microcontroller; it can easily connect to a computer with a USB cable or power it
with an AC-to-DC adapter or battery to get started. It can be tinkered without worrying too much about
making a mistake, and worst-case scenario, the chip can be replaced with a very cheap price and start
over again. The extensive large backing community and easy-to-use factors made it an attractive option
for this project, but the low numbers of analog pins, low flash memory and clock speed made it not the
right choice.

#### ***Arduino Portenta H7***

Portenta H7 simultaneously runs high level code along with real time tasks. The design includes
two processors that can run tasks in parallel. For example, is possible to execute Arduino compiled code
along with MicroPython one and have both cores to communicate with one another. The Portenta
functionality is two-fold, it can either be running like any other embedded microcontroller board, or as
the main processor of an embedded computer. H7's main processor is the dual core STM32H747
including a Cortex® M7 running at 480 MHz and a Cortex® M4 running at 240 MHz. The onboard
wireless module allows to simultaneously manage Wi-Fi and Bluetooth® connectivity. The Wi-Fi
interface can be operated as an Access Point, as a Station or as a dual mode simultaneous AP/STA andPage |31
can handle up to 65 Mbps transfer rate. Bluetooth® interface supports Bluetooth Classic and BLE. It has
3 ADCs with 16-bit max resolution and 2 DACs with 12-bit resolution. Its board power supply is 5V an
operational voltage of 3.3V. The price of Portenta is around 100€, which made it a very expensive
purchase. Its number of ADC is not enough for our project, so it made it not the right choice for our
project.

#### ***ESP32 Devkit V1***

The ESP32 DevKit V1 is one of the development boards created to evaluate the ESPWROOM-32 module. It is based on the ESP32 microcontroller that boasts Wi-Fi, Bluetooth, Ethernet,
and Low Power support all in a single chip. ESP32 is already integrated antenna and RF balun, power
amplifier, low-noise amplifiers, filters, and power management module. The entire solution takes up the
least amount of printed circuit board area. This board is used with 2.4 GHz dual-mode Wi-Fi and
Bluetooth chips by TSMC 40nm low power technology, power, and RF properties best, which is safe,
reliable, and scalable to a variety of applications. The internal flash of the ESP32 module is organized
in a single flash area with pages of 4096 bytes each. There exist two different layouts based on the
presence of BLE support. Power to the ESP32 DevKit v1 is supplied via the on-board USB Micro B
connector or directly via the “VIN” pin. The power source is selected automatically. The device can
operate on an external supply of 5 to 20 volts. If using more than 12V, the voltage regulator may overheat
and damage the device. The recommended range is 5 to 12 volts. The ESP32 DevKit V1 comes with a
serial-to-USB chip on board that allows programming and opening the UART of the ESP32 module. It
can be programmed in different programming environments like Arduino IDE, Espressif IDF (IoT
Development Framework), MicroPython, JavaScript, LUA.

![image](https://user-images.githubusercontent.com/66420672/174338389-c25a7bf2-6ff0-4eaa-a664-2e6fb347675f.png)

##### **ADC Reading**

The development board supports 18 ADC channels. Each channel has 12 bits.
So, it has a good resolution. It can be used to measure analog voltage, current and any analog sensor
which provides output in the form of analog voltage. These ADCs can also be used in sleep mode for
lower power consumption. Each ADC channel has a resolution of 12 bits which is equal to: 3.3 / 4095
where 3.3V is a reference voltage and 4095 is minimum step by ADC. This value of 4095 is calculated
from the resolution number of every microcontroller. It is calculated as follows:
212 = 4095.
This means that when we read an analog input, its range may vary from 0 to 4095. Meaning that the
minimum voltage we can measure with these ADC channels is about 80 µV. Anything less than this will
be an error.
Ideally, we expected the ADC readings to have a linear behaviour while using these pins.
However, that is not true. While conducting research on this matter, the opposite was found to be true. We decided to perform an ADC linearity test. Four simple experiments by creating several voltage
dividers to read on. Source was at 3.3V output pin of the ESP32. Then we applied 3 different steps with
4.7k 1% tolerance resistors. These are the values measure with a multimeter:

![image](https://user-images.githubusercontent.com/66420672/174338525-cb9466fd-62bf-4b5a-87a7-df882e462739.png)

The results of the Table above have been represented in the chart below. The readings
on the Table above, show when the voltage is at its maximum value, when it’s at ¾ of the maximum value, when
it’s at half and at ¼ of the maximum value. Our thought process was quite simple, as to divide both
voltage and ADC by 4 and have them as references. The most important part on this chart are the
beginning and the end of the characteristic. The behaviour means that our ESP32 cannot distinguish
3.3V from 3.2V. That means we will get the same values of 4095 from both voltages. The same happens
for a very low voltage of 0V to 0.1V. We are getting the same value of 0.

![image](https://user-images.githubusercontent.com/66420672/174338579-76d6e09b-207e-43b9-9999-41c1610d1613.png)

Another problem had arisen from our research that concerned the ADC pins. Specifically
speaking about ADC2 pins. Since our goal is to display our translated gestures using a website, then
the Wi-Fi of the board will be used. We learned that ADC2 pins cannot be used when Wi-Fi is being
used. This means, if we were to use the library of Wi-Fi, we would be getting an error at getting the
values from the ADC2 GPIO. The solution to this problem would be to only connect our flex sensors
with the ADC1 pins which would be GPIO36, GPIO39, GPIO34, GPIO35, GPIO32, and GPIO33.

##### **Voltage Regulator**

The ESP32 has a built-in low dropout voltage regulator chip called AMS1117. In our device,
its servers the function of a 5V to 3.3V linear voltage regulator, which means its main function is to
maintain a steady voltage. The AMS117 is an adjustable and fixed voltage regulator designed to
provide up to 1A output current and to operate down to 1V input-to-output differential. The dropout
voltage of the device is guaranteed maximum 1.3V, decreasing at lower load currents. Current limit is
set to minimize the stress under overload conditions on both the regulator and power source circuitry.
It has 3 fixed pins:

1. Ground
2. VOUT
3. VIN

From our research, we found that there are two versions for the AMS1117. A fixed version and
an adjustable one. Its application circuit is very simple. For the fixed version, it only needs two
capacitors and for the adjustable version only needs two resistors and two capacitors to work. Our
development board uses a fixed output voltage version. AMS1117 has six fixed versions: 1.2V, 1.8V,
2.5V, 2.85V, 3.3V and 5V. For us, we are using ASM1117-3.3, which possesses a
built-in protection against short circuit and thermal overloads. For instance, the circuity-wise thermal
protection will shut-down the linear regulator in case the junction temperature is above 165º C at the
sense point. It provides an output voltage of 3.3V by maximum output current of 1.5A and a maximum
input voltage of 12V. It guarantees a low dropout voltage (input-to-output) differential: VDROPOUT =
VIN – VOUT) of maximum 1.3V at the maximum output current of 1.5A. The dropout voltage decreases
at lower load currents and operates down to 1V dropout voltage. The on-chip trimming develops a
reference voltage of 1.25V between the output and the ground with a reference tolerance of 1.5%. This
means, we have more freedom to choose our power supply in regard to the input voltage required. We have included the electronic schematic of our voltage regulator circuit. It is comprised of 1
220Ώ resistance, 1 LED, 2 capacitors with the same value of 10µF.

##### **Power Consumption**

Since our goal is to build a portable and reliable prototype, we should consider how much does
the ESP32 consumes so we can have a better understand of its lifetime. ESP32 has different power modes
such as:

- Active Mode: The chip radio is powered on. The chip can receive, transmit, or listen.Page |36
- Modem-sleep Mode: The CPU is operational, and the clock is configurable. The WiFi/Bluetooth baseband and radio are disabled.
- Light-sleep Mode: The CPU is paused. The RTC memory and RTC peripherals, as well as
the ULP coprocessor are running. Any wake-up events will wake u the chip.
- Deep-sleep Mode: Only the RTC memory and RTC peripherals are powered on. Wi-Fi and
Bluetooth connection data are stored in the RTC memory. The ULP coprocessor is
functional.
- Hibernation Mode: The internal 8 MHz oscillator and ULP coprocessor are disabled. The
RTC recovery memory is powered down. Only one RTC timer on the slow clock and
certain RTC GPIOs are active.

While we want to have a website open during the whole time the device is on, and the ESP32
will be constantly communicating with the website, the power mode will be stated as ‘Active’. To have a better understanding about the development boards power consumption in an Active
Mode, we will be including a table displaying the RF Power-Consumption Specifications, from the ESP32 DevKit V1 documentation. We can approximate that our power consumption would be 240 mA, considering that we must
keep the development board and website communicating constantly to update the data. The formula to
find the battery life is as follows:
Battery Life (h) = Battery Capacity (mAh) / Device consumption (mA)
For example, if we were to have a battery with the capacity of 2000 mAh, and our maximum
consumption, in ideal conditions, we would have the device running for 8 hours and 19 minutes straight
without interruptions, which is enough for our project.

### Development Board

Regarding the power supply, a suitable battery was searched for to match the input voltage of the
chosen development board. As said before, our ESP32 requires an input voltage of 5V to 12V, so any
battery that has that output is enough for our project. We will be conducting research for rechargeable
battery options because we would like for the lifetime of the prototype being turn on to be as much as
possible without changing the battery. 

Three most common rechargeable battery types include NickelCadmium (NiCd), Nickel-Metal-Hydride (NiMH), and Lithium Polymer (LiPo). Each of these is a good
choice for projects and they all have their benefits and drawbacks. Nickel-Cadmium batteries have a
very high cycle count, and they are typically the cheapest of the three options. However, this type of
battery has a relatively low energy density, so they offer less capacity per cell than the other two types.
On the flip side, NiCd batteries can often deliver very high currents, which makes them perfect for power
tools. Note that NiCd batteries contain toxic heavy metals, which makes them more difficult to recycle.Page |38
Nickel-Metal-Hydride batteries are like NiCd cells. However, NiMH batteries offer an improvement in
capacity over NiCd batteries. One major drawback of NiMH cells is their high self-discharge rate. Li-Po
and Li-Ion batteries have a significantly higher energy density compared to typical NiMH and NiCd
cells. However, this benefit also means that you usually pay more for Li-Po and Li-Ion batteries. Besides
the increased price, lithium batteries always require monitoring by a battery management system, as
these batteries are sensitive to improper handling. Note that Li-Po batteries come in various shapes and
packages, of which some can be very flat. This makes Li-Po cells perfect for handheld devices such as
modern smartphones. Li-Ion batteries often come in larger sizes and are typically used in applications
where size isn’t critical. Note that there is not a single type of Li-Ion or Li-Po battery. Instead, the
category of lithium batteries comprises a whole range of different chemical formulations that all have
their very own pros, cons, and recommended applications.

In our case, a Li-Ion was chosen because they can be recharged many times and are quite stable
and efficient. They tend to have a higher energy density, voltage capacity and lower self-discharge rate
than other rechargeable batteries. This makes for better power efficiency as a single cell has longer
charge retention than other battery types. For the battery to be included and connected with the rest of
the prototype, it should be connected in a certain way. Either through connecting the VIN and GND pins
of the development board or through USB. As mentioned above, our chosen board has a micro-USB
type ‘B’ female. To have a much consistent connection and reliable to connect and disconnect, it was
decided to use a battery shield which will have an USB to make the connection with our board. The size
of this shield should be able to be held on the back of the hand of the user and it should have the option
of being rechargeable. The power supply’s purpose will be simple. It will be connected through USB
type A with the development board with the right input voltage. Since the development board requires
an input voltage of 5 V and has an operational voltage of 3.3V, it will be supplied the exact amount. The
battery shield chosen is the 18650 Battery shield (V3). It was considered for multiple reasons. This shield
is a cheap and portable power supply that can accommodate an ‘unprotected’ single-cell lithium-ion
battery. It also includes a standard USB type ‘A’ female connector, one power on/off switch and a micro-USB
type ‘B’ female for recharging. Its key specifications are as follows:

• Battery charging input: 5V/500mA typical via micro-USB port

• Power supply output: Switched 5VDC via USB type ‘A’ port, 3x 5VDC (VDC= volts
to direct current) (up to 4A) connectors, and 3x3VDC (up to 1A)

• System status indicators: Battery charging and battery charged LEDs

• Battery protection mechanism: Battery overcharge and deep discharge

The background electronics are a clever blend of three requisite circuits a lithium-ion
battery charger circuitry, a battery protection circuitry, and a dc-dc boost converter circuitry. Refer to
the annotated image provided below to get a deep insight on the underlying electronics. In the shield,
the dc- dc boost converter chip is used to deliver 5VDC (4.99V) through the USB ‘A’ socket and 5V
male-header points, generated from the available 3.7V-4.2VDC Li-Ion battery output. The second
channel output, marked as 3V but 3.3V on the dot, is supplied by the parallel combination of three
positive voltage regulator chips. The 3.3VDC supply is derived from the 3.7V-4.2VDC Li-Ion battery
output (not from the 5VDC output)

![image](https://user-images.githubusercontent.com/66420672/174339083-54c56ddf-b4e8-47c6-b6ea-0db6693cb14e.png)

This device is composed of many components. They will be described by declaring their component
initials which can be check at its Schematic.

- U9 WD01A = Li-Ion battery protection chip
- F1 8205A = Dual N-Channel MOSFET
- U2 TP4056E = Li-Ion battery charger chip
- U7 FP6298 = 4.5A current mode DC-DC boost converter chip
- U4, U5, U6 (XC6206) = Positive voltage regulator chip (3.3V)Page |40
- L1 Green LED = Battery done charging indicator
- L2 Red LED = Battery charging indicator
- S1, S2, S4 = Schottky Diodes

![image](https://user-images.githubusercontent.com/66420672/174339127-b9741c29-c8bc-4bcd-b324-41db76487393.png)

### Flex Sensor

Capturing the bend of the fingers could be done in very few ways. Judging from the research
conducted beforehand on similar projects, flex sensors proved to be a good and efficient way of
measuring the bend of the fingers. Our options regarding the decision on acquiring the right flex sensor
for our prototype were limited. Generally, there are 3 main types of flex sensors: Conductive ink-based
flex sensors, fibre optic flex sensors and capacitive flex sensors. The conductive ink-based flex sensors
are quite common for projects of this nature. Capacitive and fibre optic flex sensors can be used more inPage |41
industrial and professional equipment. Conductive ink-based flex sensors are unipolar sensors, which
means the change of resistance is true only if you bend it in one direction. Bending the sensor on the
other direction does not change its resistance. It uses conductive ink whose resistance varies when bent.
The ink may contain carbon or silver to make it conductive. The spacing between carbon particles are
lager when bent and close when straight which results in a change of resistance.
Regarding the purchasing options, there were only two. 2.2 inches and 4.5 inches flex sensors
were available. 

Five 4.5 inches flex sensors were purchased instead of the 2.2 inches because they better
match the length of the fingers. The main computing device is going to be used to configure input and
output pins for each sensor, setup a clock speed, configure communications with the ADC, configure
communications with I2C pins, control sensor data, and send valid data to a Wi-Fi module. Flex Sensors
will be manipulated in the algorithm to decide whether the finger will be closed, open or to determine
exact positions for them.

##### **Power Consumption**

Each Flex Sensor is treated as a variable resistor whose resistance increases which the sensors
bending. Each sensor constitutes a part of its own voltage divider circuit, whose output is processed
through one of the development board’s analog-to-digital converters. The voltage provided from the
controller will be changing because of how much the corresponding finger is bent, which can lead to
problems while using the device. More specifically speaking, if the flex sensor would be changing its
value, the voltage would do as well. To fix this issue, voltage dividers will be placed before the Flex
Sensors. Voltage divider’s purpose in this case is to supply analog voltage values from
divider central point where both two resistors are connected. Voltage dividers only divides power
supply voltage value in proportion of Resistors values. One resistor has fixed value other value is
changing. Imagine two values are equal. Then voltage will be divided by 2.

![image](https://user-images.githubusercontent.com/66420672/174339269-4a46b2b5-439c-489c-8769-c8e2bab4b698.png)

The flex sensors were measured using a multimeter to determine their values. We agreed to set
the resistance when the sensor is straight as 12.3kΏ and for when it’s bend at 180º, it’s 29kΏ. By
connecting the sensor to a voltage divider circuit, the resulting voltage can be calculated from the
formula:

![image](https://user-images.githubusercontent.com/66420672/174339328-6d533eee-0c62-4259-a789-aa933124299a.png)

So, if we wanted to find out the output voltage, taking the flex sensor when it is straight and the
power supply voltage of 3.3V, according to the formula, it would be equal to 1.47V and for when we
are calculating for when flex sensor is bent, we get 0.846V.

![image](https://user-images.githubusercontent.com/66420672/174339389-b67e585f-125a-4b28-93ac-e6d38b4f4093.png)

Now, to find the current consumption of each flex sensor we would use this formula:

![image](https://user-images.githubusercontent.com/66420672/174339507-e483cf93-b7d1-49b0-ac5b-46479b146936.png)

We can see that the circuit consumes very little current making it an energy efficient circuit,
considering that the board will reach around 240mA as consumption. This makes the use of the 10kΏ a
good value to choose for the voltage divider.
Regarding the value of voltage that will serve as an indicator for us to know if the flex sensor has
been bent, we decided that bending the sensor 90º (see Figure 24). This means that we can calculating
the resistance at half-way to our maximum bend value of 180º. This resistance is equal to:

29000Ώ – 12300Ώ = 16700Ώ.
16700Ώ / 2 = 8350Ώ.
12300Ώ + 8350 Ώ= 20650Ώ

We can calculate the voltage of this threshold as follows:

![image](https://user-images.githubusercontent.com/66420672/174339574-ca9fe9ad-84f0-47d0-8d8c-f26934f831f2.png)

From our results we can understand that the voltage of 1.07V will be understood as a bend in the
flex sensor with that value.

### Accelerometer and Gyroscope

Regarding both accelerometer and gyroscope, the idea was based on the solution in Review 1,
where the team was using a MPU6050 module which contained both an accelerometer module and a
gyroscope module. It combines a 3-axis gyroscope and a 3-axis accelerometer on the same silicon die
together with an onboard Digital Motion Processor (DMP) capable of processing complex 9-axis
algorithms. This will help us to measure acceleration, velocity, orientation, displacement, and many
other motions related parameter of the prototype. The price of this is 5.5€ which made it a very
reasonable and efficient option for the realization of our prototype. It is comprised of 5 pins, INT, SCL,
SDA, GND and VIN. 

The INT is the interrupt signal which is an optional pin to connect. It indicates that
data is available for MCU to read. SCL stands for Serial Clock and is used for providing clock pulse for
I2C communication. SDA means Serial Data and is used for transferring data through I2C
communication. VIN will provide the power for this module, can be +3V to +5V depending on the added
power supply. In our case, the power will supply 5V into the board. GND stand for ground and connected
the system to ground. The main features or the MPU6050 are:

• MEMS 3-axis accelerometer and 3-axis gyroscope values combined,
• Power Supply: 3-5V,Page |44
• Communication: I2C protocol,
• Built-in 16-bit ADC provides high accuracy,
• Built-in DMP provides high computational power,
• Built-in Temperature sensor.

A gyroscope to capture the orientation and the angular velocity of the hands. Gyroscope will prove
useful for certain gestures that will require rotary movement in space. Accelerometer will be used to
measure the acceleration of the hand, which will be useful for gestures of phrases or words that need
stretched movement of the hand in space.

![image](https://user-images.githubusercontent.com/66420672/174339685-b53cd42b-e52c-4275-a50f-ee5fb95bd89b.png)

## Schematic Diagram

The first step taken for the realisation on this prototype was to design the schematic by placing
the components on a simulated breadboard to have a clearer view of how everything would be connected.
This proved to be quite helpful as a step before placing the components a real breadboard and start
experimenting. was designed using Altium Designer. This would
prove very useful, because the schematic would be imported easily for the next step of creating the PCB
using the same software. In the schematic, we can see how the components are connected with each
other. The flex sensors are shows as variable resistors with the names of Flex 1, Flex 2, Flex 3, Flex 4,
and Flex 5. Each sensors had their resistances measured beforehand to decide their value without any
force put into. This proved an approximated value of 12kΏ. Each of these sensors is connected to their
own voltage divider. These resistances have been assigned a value of 10kΏ. Each flex sensor has been
connected to an ADC pin of the ESP32. These pins are GPIO34, GPIO 35, GPIO 33, GPIO 32 and
GPIO39. We can also see in the schematic design that the MPU6050 module is connected without
development board as well.

![image](https://user-images.githubusercontent.com/66420672/174339795-919f377b-5427-48b1-b03b-03b3396c9b92.png)

The ESP32 has 6 Analog-To-Digital pins assigned as ADC1 and 9 Analog-To-Digital pins
assigned as ADC2. Since our goal is to send the data gathered to an opened webpage, this means that
the flex sensors would be able to connect to ADC1 pins only. From the schematic, we can
also see that the MPU6050 module is connected with the board to the specified pins. In the Pinout Figure
of the ESP32, we can see that GPIO21 and GPIO22 have the following names assigned: I2C SDA and
I2C SCL respectively. Therefore, they are connected to the pins of the same names of the module. Every
VIN pin has been connected and so has the GND pins. It is displayed that the input voltage of the circuit
will be 3.3V as is the operating voltage of the development board. The 18650 battery in-use are the
18650 US18650VTC4 Li-Ion 3.7V 2100mAh 30A. 

The ESP32’s lifetime on battery power has not been
tested, but as an approximation it could last around 4 months without charging the battery. Since the
board will be awake, it will need to be on during the whole time. Our main objective is to enable the user
of the glove to be able to fully communicate with another person through the use of a website, which
will serve as a lobby where anyone can connect with. This website will be run on the development board
at the same time it is reading the sensor data. As long as the user of the glove has a mobile phone and
internet mobile data, it will make the communication much easier. They will be taken to a specific IPPage |47
address where this webpage is opened. This was an option we explored as a very efficient one, amongst
other options. We could have developed an easy-to-use mobile application that would’ve performed the
same tasks, but it opened the way to new problems. Such as for what reason would someone download
this app, taking into consideration the chances a person has to meet someone with a hearing impairment.
Even if they did, it would’ve made it more difficult to get the message across to download it in order to
communicate. How would someone know the existence of this app? What if in an extreme situation,
there was a need for the interaction of a person and a hearing-impaired person? What if the person who
will need to get the app does not have enough internet to download it? All these obstacles made the
development of an app obsolete, as it would lead to more headaches and annoyances throughout the
daily life. We decided to research on this matter as well as it is very important how we will be displaying
the translated gesture.

## PCB Design

From the schematic design, all the connections, components and names of components have been
imported to create the PCB of this prototype. The PCB was designed while have the enclosure design in
mind. This means that to properly design the PCB, the dimensions should’ve have been decided before
creating it. Therefore, the dimensions of this PCB are 70x50mm. According to the design of the
enclosure, the longest part would be placing the 18650-battery shield which would be very near the PCB.
The PCB’s dimensions resemble the back of the hand, from the end of the wrist till the beginning of the
fingers. PCB has two layers, a top and bottom one. It has a top and bottom overlay with the name of the
author and its logo and the logo of the university on the back. 4 mounting holes have been put on the
four corners with the sizes of 2.5M screws. Every resistor has their name on the top overlay, just like the
development board and MPU6050 module. The PCB has a common ground, which means the ground
pins are not connected through route connections but go through the same layer. This is a very effective
tool to minimize the routes through the PCB, making less chaotic. Via stitching was used to tie together
large copper areas on different layers to create a strong vertical connection through the board structure.
This helps maintain a low impedance and short return loops. The width of the board was decided to be
a standard 1.6 mm. The PCB was designed and ordered through PCBWay, and it arrived surprisingly
quick, in around 5 days. When ordering our PCB, Gerger Files were generated and the Drill Holes files
that are necessary for the manufacturing and development of our PCB.

![image](https://user-images.githubusercontent.com/66420672/174339876-3b0ad631-d8bb-4b01-83c1-1213fb321a04.png)

![image](https://user-images.githubusercontent.com/66420672/174339891-398759ca-d42e-4021-bc85-684f90bfa280.png)

The resulting PCB that was ordered and shipped. PCB was ordered twice. The first time’s
resulting PCBs had two main mistakes. The place where the MPU6050 would be soldered into, was too
close to the development board and Flex sensor 5 was connected with the wrong the ADC pin of the
board. It was connected to a ADC2 pin, the ESP32’s ADC2 pins
cannot be used while using the Wi-Fi module. Redesigning the PCB, the stitching holes were kept the
same. The holes for the MPU6050 have been moved up by 3 mm leaving more space for it and the Flex
Sensor 5 was connected with GPIO 39 of the ESP32.

## Software Framework

After designing the PCB, we put our attention to create a very efficient algorithm that would
gather data, analyse them, process them, check them, open a website, create a webpage, and update the
values. In this chapter, we are going through the Software Framework, which explains the logical idea
of the whole algorithm. From the extensive research, it was decided that the prototype will be working
using a dataset in its algorithm, discarding completely the idea of including machine learning. We will
be exploring the ESP32 and its entire capabilities while focusing on speed of transmission of data.
The framework starts from booting the microcontroller. As soon as it
is turned on, it will initialize the Accelerometer and Gyroscope sensors. This means, a function will
perform a checking statement to verify whether MPU6050 is connected or not. If it’s not, then the
MPU6050’s LED won’t turn on. In this situation the main board can be restarted by pressing the EN
Button. If the problem is persistent, then this means there is a problem with the connection between the
main board and the sensor module. This explains the significance to this simple function that is critical
to the communication between the device and the user as it indicates the state of functionality. It is very
important to have visual representation of the status of the device the user is using. This function is one
of the few functions that were added to serve as debugging functions in case problem would arise.
Whenever the board is booted, a red LED is turned on to indicate it. 

The next part is calibration of the
flex sensors. Here the user has 15 seconds from the boot of the board to open and close their fingers to
calibrate the flex sensors values. The ESP32s ADC pins gathering of data fluctuate extensively, with the
values changing for the same position of the finger every time the board is booted. This proved that the
specified maximum and minimum values of flex sensors resistance would be incorrect. The
measurements would be less than the minimum and more than the maximum than the measurements
conducted with a multimeter for each flex sensor. Calibrating the flex sensor would give each flex sensor
their individual maximum and minimum, balancing out the values differently each time the board would
boot. 

After taking care of every sensor the prototype has, the next step would be to open the website.
The board has been given specific credentials to connect to a Wi-Fi in its surrounding. It will scan the
area and if it finds the same name of the router or switch device, it will connect to it, putting in the
password provided as well. In this stage, the board has successfully initialized a Transmission Control
Protocol (TCP) server. This is a connection-oriented communication protocol that facilitates the
exchange of messages between computing devices in a network. If the server has been initialized, then
the board connects to it. From experimenting, it has happened that the device may not find the specified
Wi-Fi, or there may be a problem with the transmission of the Wi-Fi. This issue leads to the device not
being able to connect to the Wi-Fi and the website cannot be open successfully. In the case where the
connection is successful, the board opens the website. This concludes the setup part of the algorithm,
which is displayed to the user with a blue LED turning on, indicating that the glove is ready to be used.
In the case explained beforehand, where the website would not connect properly, the user could not see
the blue LED after the roughly 15-16 seconds from booting the board. This can be fixed by manually
pressing the restart button EN. The next part is conducted in the loop function of the board. It starts with
the gathering the data from each individual sensor. 

There is a specific function for data of accelerometer,
one for gyroscope and one for flex sensors. Each of these functions is called in the loop function. The
values gathered are checked with the constraints of the dataset, which itself is its own function. Datasets
are if constraints that hold specific values for every sensor and are equal to one specific word, number
letter or phrase. When one of these if constraints is fulfilled, they send a string value with the right result.
This result is sent to the webpage and gathered there where it would be displayed as a translated gesture.
So, since the webpage remains open indefinitely until the user restarts, or the device is disconnected
from the Wi-Fi. If new data was not received, then nothing would change in the webpage displaying the
translate gesture. This was managed through a function that makes the current displayed gesture as
‘current reading’. Since we know that the loop function keeps running indefinitely, the displayed gesture
would print every half a second. This function will display the next gesture when another constraint is
fulfilled, naming it as ‘new gesture’. So, this constant loop will keep reading new values, checking with
the datasets, and updating whenever gestures change, reaching our desired goal.

![image](https://user-images.githubusercontent.com/66420672/174340017-71bb2dfa-e139-4036-aa53-c0a97a11902f.png)

## Enclsoure Design

To design the enclosure, the PCB dimensions were taken into consideration. The idea behind the
enclosure is to build a sturdy box that would hold both the power supply and development board. It is
going to have an upper side and a lower side. With the
already mentioned specifications on what our goal is, the enclosure will have 2 openings on the eastern
side, for the USB type A of the 18650-battery shield and one for the micro-USB type B of the ESP32.
Two smaller openings would go on the southern side, where the smallest would be for the switch that
the battery shield has and the bigger one would be for the micro-USB type B which will be used to
charge the battery inside. Since our prototype requires a certain level of conveying stages of functionality
to the user along with the restart button EN being a crucial part when a problem would arise, an opening
would be positioned on top of the development board. This opening would cover the two LEDs and
make it possible for the user to manually press the restart button EN. One other opening on the top side
is going to be positioned on top of the flex sensor markings. This will leave space for the connectors to
be soldered onto the PCB and they will be as high as the enclosure. This will protect them from outside
factors or accidental pushes. Enclosure was designed with a logo to give it a more personal touch and
serves as a branding mark. It will have two smaller opening it the thickest side, the nearest with the
battery shield, one to recharge the battery using a micro-USB type B, and the other opening will be used
for the switch, to turn the battery on or off. The opening for charging has the dimensions of 5x5mm and
the opening for the switch has the dimensions of 4x4mm. To have the enclosure sit on the back of the hand, we designed it in a way that it could be strapped
onto the hand. This was done through two holes on both sides where a strap with the width of 2mm
would go inside and around it, connecting with a buckle. The idea was inspired from professional digital
photographing equipment that are carried around strapped onto the user’s neck. The furthest holes,
furthest away from the battery shield, would be connected around with a strap, without the need of a
buckle. This would serve only as s supporting strap that will stand above the thumb. The other hole
would be connected together using a buckle that would make the connection around the wrist. This way,
the enclosure would stay and rest in place without moving while the user is performing gestures.
Mounting holes for 18650 battery shield and PCB support 2.5M screws and the lower lid can be mounted
using holes supporting 3M screws. The design was made using Autodesk’s Fusion 360 and SolidWorks.
The thickness of the walls has been put as 2mm across the whole device. The real model was 3D printed
and mounted together with the other components. Results of the design have been displayed.

![image](https://user-images.githubusercontent.com/66420672/174340115-3955b8e7-8d9b-44ea-ae90-db8df0338df5.png)

![image](https://user-images.githubusercontent.com/66420672/174340133-4bd309d0-7a1a-40fd-a1af-3c66757dec6f.png)

## Results and Testing

The nature of this PCB, required movement of the board in many directions, making it harder to
solder components. It was accomplished from the help of ‘Flexible Helping Hands Soldering Station’.
This station made it much easier to solder the connectors and the MPU6050 chip, which proved to be
harder to keep in place to solder. Soldering iron used has been displayed for full disclosure in Appendix
5. It was equipped with a conical tip for greater precision during most of the soldering process, and a
bent tip for the development boards pins since they are quite close with each other. The soldered resulting
PCB has been shown below:

![image](https://user-images.githubusercontent.com/66420672/174340211-f8400e4b-00cb-467c-b771-5bc8e3683e48.png)

Regarding the printing of the enclosure, both upper and lower lid have been 3D printed. Since the upper lid is a
complete opened area, a lot of supporting fibres were added inside it entirely covering the empty spaces.
These supports would be cut out after it had been printed entirely. This was added to not have the printing
fail. The printing of the upper lid took roughly 12 hours and for the lower lid, around 2 hours. Both were
printed successfully with the first try, so there was no need for more printing.

![image](https://user-images.githubusercontent.com/66420672/174340300-2f8ad26d-2334-46ec-af18-fe2571690e66.png)

As it was mentioned during the Enclosure Design, the lower lid has mounting holes for M3
screws. M3 nylon screws have been used to mount up the lower part unto the upper part. For the PCB,
it is needed 2.5M screws. PCB was placed carefully onto the holes, while taking care of the connectors
of flex sensors to pop out from the opening specified. Battery shield has been mounted in the
corresponding place using 2.5M screws, just like the PCB. Results of mounted components has been displayed.

![image](https://user-images.githubusercontent.com/66420672/174340357-2a9598a6-e6a1-403c-8fb9-e271d52ee879.png)

Regarding the glove, flex sensors have been placed into each finger. Two 5mm cuts were made in each
finger, with a 1mm to 2mm distance from the first cut, depending on the length of the finger. The idea
was to make a path for the sensor so it would be harder for it to fall off the glove. The cloth material
definitely helps with friction, making it impossible for the
sensors to fall away. These sensors go around and inside these
cuts, making them like going in and out small pockets, and
appearing only by a bit outside of the glove, on these pockets.
Each of them, has been cold soldered with the male header
pins of the PCB connectors. This way we have concluded in creating
the enclosure and glove. After connecting the enclosure and the flex sensors on the glove, the strap and buckle were
prepared. Both sides of connecting straps have been sewed for greater grip on the hand. The final
completed prototype is shown below.

![image](https://user-images.githubusercontent.com/66420672/174340432-57d2c802-1690-4963-9ec4-967df0c1e23d.png)

![image](https://user-images.githubusercontent.com/66420672/174340459-00f5c431-12f1-4bc6-8dc8-2457442d26a8.png)

After finishing the mounting and creating the prototype, we continued to test. This means we
would start and test the functionality of the algorithm. Many gestures have been implemented into the
prototype. For the time being, the glove can translate number 1, 2 3 and 4. It can say the phrases ofPage |68
‘Hello!’ and ‘I love you!’. It can say the words ‘My’, ‘Name’ and it can translate the letters ‘T’, ‘E’, ‘D’
and ‘I’. The next set of figures will be a representation of our work, displayed with a proof of hand
gesture, website reading and a representation of the real gesture in ASL.

![image](https://user-images.githubusercontent.com/66420672/174340517-0693193f-eb43-4ffc-a641-42c6d876f303.png)

![image](https://user-images.githubusercontent.com/66420672/174340550-afc28076-b054-45f6-85db-84c03e0a8aa6.png)

## Summary of work results

After testing our prototype, we can safely say that we have reached our goal of developing a
responsive, portable, and durable device. The website works as intended and as designed. It gathers and
translates the gestures performed in real time. We have displayed many phrases, words, numbers, and
letters. The entire project was started from an idea. An idea that was stated as a solution to a problem. It
was intended to solve the difficulty gap between hearing-impaired people and the hearing world, by
making their daily life safer and easier. It was meant to surpass the designs of previous projects.
The process started by building a block diagram, deciding what relationships the many devices would
have with each other. It continued into much extensive research about similar works previously made,
which made the idea clearer. This way we could decide which roads to undertake without spending our
time exploring many ideas.

We constructed the schematic design using the components along adapting each of their parameters
with each other. That step made the building and designing the PCB much easier by importing the already
done assets onto Altium Designer. The PCB was made while having in mind an idea for the enclosure.
Algorithm was developed in a quite simple manner, with many void functions, by making the whole
code readable to anyone and efficient. This way, we could focus on performance issues, small fixes on
the datasets of gestures, and adding more gestures as features. The data was uploaded in a JSON variable
into our Asynchronous server. Enclosure was built later, which was the most challenging part of this
whole project. It required many trials and errors.

Many problems arise on designing the openings for the battery shield and the PCB. Looking at the
work in a more critical point of view, the opening for the on/off switch of the battery shield could be a
couple more millimeters bigger on both dimensions, and so could the opening for the charging microUSB type B. Using SolidWorks for the enclosure proved quite useful because the design was done part
by part. Each component was designed separately to have a better picture of the idea. The testing revealed
many smaller defects of the prototype. The wires can be insulated for a more professional look. The flex
sensors inside the glove could have been sewed for a better grip, leaving room for smaller improvements.
After the implementation, the device meets its intended requirements and objectives, while achieving
every goal set at the beginning of this project. The designed device is extremely simple in construction,
both in PCB, enclosure, making it a reliable product with a low-cost production.

