.text

# Set up interrupt descriptor table
.global load_idt # Allows C/C++ code to link this
.extern IDTP # External pointer from our calling location
load_idt:
	lidt IDTP # Load idtp into the interrupt descriptor table
	ret # Return function
