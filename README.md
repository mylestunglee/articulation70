# articulation70

The _articulation70_ keyboard is a successor to the [articulation80](https://github.com/mylestunglee/articulation80), with a better layout and LEDs.

It features:
- Reversible PCB to reduce manufacturing costs for hobby usage
- Variable pinky stagger, supporting ±1 mm vertically offsetted soldering options
- 3 × 6 main body, 3 thumb switches, 2 corner switches and 3 × 4 number pad
- Kailh Choc V1 hot-swap support
- A breakaway-able number pad
- Serial or I2C connection between halves
- Pro Micro-compatible controller support, however a micro-controller with more pins are required to operate LEDs 2 and 3. 
- 3 LEDs

## Build Instructions

This build is very similar to many hobby keyboards. Please refer to the instructions for  [articulation80](https://github.com/mylestunglee/articulation80). You will need a soldering iron.

#### Which jumpers do I need to solder?

If using serial, then solder J1, and J4. If using I2C, then solder J2, J3 and J4. Solder on the back of each respective half.

### Build Parts

I would recommend substituting for cheaper or easier to source components when possible.

| Component | Quantity | Manufacturer Code | Purchase Link | Remarks |
|:-|:-|:-|:-|:-|
| PCB | 2 |
| Left plate | 1
| Right plate | 1
| Micro-controller | 2 | Elite-C | [Link](https://mechboards.co.uk/products/elite-c-v4)
| Through-hole TRRS jack | 2 | PJ-320A | [Link](https://mechboards.co.uk/products/trrs-jacks?variant=40330077241549)
| TRRS cable | 1 | | [Link](https://mou.sr/3QC5ykN) | Also called a 4-pin 3.5mm audio auxiliary cable |
| Reset button | 2 | PTS526 SM15 SMTR2 LFS | [Link](https://mou.sr/3tXtsOQ) | Different button operating force are possible
| 150Ω Resistor  | 3 | RC1206FR-07150RL | [Link](https://mou.sr/3QEyQzo) | Optional, for LEDs
| 4.7kΩ Resistor  | 2 | RC1206FR-104K7L | [Link](https://mou.sr/46XoOPE) | Optional, for I2C connection
| SMD Diode | 70*    | 1N4148W-TP | [Link](https://mou.sr/3D01KSP) | Any SOD-123 recommended |
| Hot swap micro-controller sockets | 5 | 315-43-112-41-003000 | [Link](https://mou.sr/3QfEIO2) | Recommended
| Hot swap pins | 52 | 3320-0-00-15-00-00-03-0 | [Link](https://www.mouser.co.uk/ProductDetail/Mill-Max/3320-0-00-15-00-00-03-0?qs=s8Nb1z4Wn%2FQ16WBIwCPrTw%3D%3D) | Recommended |
| Rubber feet | 12** | SJ-5302 CLEAR | [Link](https://mou.sr/3QFq1oL)
| Hot swap key sockets | 70*      | CPG135001S30 | [Link](https://mechboards.co.uk/products/kailh-choc-hotswap-sockets)
| Key Switch | 70* | CPG135001 | [Link](https://www.aliexpress.com/item/1005005446722280.html)
| Key Cap | 70* | | | Ideally different key caps for thumbs |

*Adjust for number of keys desired.

**Adjust for number of number pads.

## How to order PCBs and plates

I ordered from JLCPCB, however there are many other manufacturers. Take a look at [PCBShopper](https://pcbshopper.com/).

For the PCBs, I used:
- Base material: FR-4
- PCB thickness: 1.6 mm 
- PCB colour: black 
- Surface finish: LeadFree HASL
- Remove order number: Yes


For the plates, I used:
- Base material: FR-4
- PCB thickness: 1.2 mm 
- PCB colour: black 
- Surface finish: HASL (with lead) because the unleaded option greatly increases cost and the plates do not have any pads.
- Remove order number: Yes

## How to adjust the layout

