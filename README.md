# QEMU_OS
Adding additional features and system calls into xv6 architecture based QEMU terminal.

# QEMU
![0_qemu](https://user-images.githubusercontent.com/61384707/85681154-a2e7f580-b6e8-11ea-91ab-f55614748d43.jpg) 

QEMU is used to emulate devices and certain privileged instructions and requires either the KQEMU or KVM kernel modules and the host operating system to provide a virtual machine environment. It is typically used to run Windows and DOS applications on x86-based Linux computers.

QEMU is an operating system created for learning purposes and for fun. \
It is written mainly in C++. 

# Features
QEMU is a FAST! processor emulator using dynamic translation to achieve good emulation speed.

operating modes : QEMU has two operating modes:

- [x] **system emulation**
Full system emulation. In this mode, QEMU emulates a full system (for example a PC), including one or several processors and various peripherals. It can be used to launch different Operating Systems without rebooting the PC or to debug system code.

- [x] **user mode emulation**
User mode emulation. In this mode, QEMU can launch processes compiled for one CPU on another CPU. It can be used to launch the Wine Windows API emulator or to ease cross-compilation and cross-debugging.

- QEMU can run without a host kernel driver and yet gives acceptable performance. It uses dynamic translation to native code for reasonable speed, with support for self-modifying code and precise exceptions.
- It is portable to several operating systems (GNU/Linux, *BSD, Mac OS X, Windows) and architectures.
- It performs accurate software emulation of the FPU.
- QEMU user mode emulation has the following features:
- Generic Linux system call converter, including most ioctls.
- clone() emulation using native CPU clone() to use Linux scheduler for threads.
- Accurate signal handling by remapping host signals to target signals.

QEMU full system emulation has the following features:\

- QEMU uses a full software MMU for maximum portability.
- QEMU can optionally use an in-kernel accelerator, like kvm. The accelerators execute most of the guest code natively, while continuing to emulate the rest of the machine.
- Various hardware devices can be emulated and in some cases, host devices (e.g. serial and parallel ports, USB, drives) can be used transparently by the guest Operating System. - Host device passthrough can be used for talking to external physical peripherals (e.g. a webcam, modem or tape drive).
- Symmetric multiprocessing (SMP) support. Currently, an in-kernel accelerator is required to use more than one host CPU for emulation.

# Install QEMU

sudo apt update \
sudo apt install qemu \
git clone git://github.com/mit-pdos/xv6-public.git \
make \
make qemu-noxCopy 

Here are the steps: 

**Step 1** – Install qemu: 
$ sudo apt install qemuCopy \
If you have 64 bit OS there is a chance Makefile will not be able to find qemu. In that case you should edit the Makefile at line 54 and add the following code: 

QEMU = qemu-system-x86_64Copy \

**Step 2** – Install xv6

- Create a directory, and clone xv6 to that directory: \
$ git clone git://github.com/mit-pdos/xv6-public.gitCopy 

**Step 3** – Compile xv6 \
$ makeCopy 

**Step 4** – Compile and run the emulator qemu: 
$ make qemuCopy \
The emulator will start but it will echo on the terminal too. Better to run it with the following frag (preferred): \
$ make qemu-noxCopy \
Also, for gdb enabled execution run: \
$ make qemu-nox-gdbCopy \
To enter the qemu console at any time, press ctrl+a, then c. If you want to exit, simply type “quit” to exit the emulator

**Step 5** – Write an user application (eg: bla)
5.1) Create a copy of an existent program like wc and name it as your new user program (eg bla.c):\
$ cp wc.c bla.cCopy\
5.2) Edit bla.c with your favorite editor. Take a look at the source code examples of existent commands, in order to see the syntax of the available functions of xv6 (they are slightly different).\
5.3) Modify the makefile of xv6 to include bla.c: The simplest way is to open the makefile, search for wc and add bla next to it whenever it appears on the makefile\
5.4) Clean and recompile xv6.\
The new command should be available.
