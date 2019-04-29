
lyra2zz.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <lyra2zz_hash>:
   0:	41 54                	push   r12
   2:	55                   	push   rbp
   3:	48 89 fd             	mov    rbp,rdi
   6:	bf 0e 00 00 00       	mov    edi,0xe
   b:	53                   	push   rbx
   c:	48 89 f3             	mov    rbx,rsi
   f:	48 81 ec d0 00 00 00 	sub    rsp,0xd0
  16:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  1d:	00 00 
  1f:	48 89 84 24 c8 00 00 	mov    QWORD PTR [rsp+0xc8],rax
  26:	00 
  27:	31 c0                	xor    eax,eax
  29:	4c 8d 64 24 40       	lea    r12,[rsp+0x40]
  2e:	e8 00 00 00 00       	call   33 <lyra2zz_hash+0x33>
  33:	4c 89 e7             	mov    rdi,r12
  36:	e8 00 00 00 00       	call   3b <lyra2zz_hash+0x3b>
  3b:	ba 70 00 00 00       	mov    edx,0x70
  40:	48 89 ee             	mov    rsi,rbp
  43:	4c 89 e7             	mov    rdi,r12
  46:	e8 00 00 00 00       	call   4b <lyra2zz_hash+0x4b>
  4b:	48 89 e6             	mov    rsi,rsp
  4e:	4c 89 e7             	mov    rdi,r12
  51:	48 89 e5             	mov    rbp,rsp
  54:	e8 00 00 00 00       	call   59 <lyra2zz_hash+0x59>
  59:	48 8d 7c 24 20       	lea    rdi,[rsp+0x20]
  5e:	48 83 ec 08          	sub    rsp,0x8
  62:	31 c0                	xor    eax,eax
  64:	6a 08                	push   0x8
  66:	41 b9 20 00 00 00    	mov    r9d,0x20
  6c:	49 89 e8             	mov    r8,rbp
  6f:	b9 20 00 00 00       	mov    ecx,0x20
  74:	6a 08                	push   0x8
  76:	48 89 ea             	mov    rdx,rbp
  79:	be 20 00 00 00       	mov    esi,0x20
  7e:	6a 08                	push   0x8
  80:	e8 00 00 00 00       	call   85 <lyra2zz_hash+0x85>
  85:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
  8a:	48 89 03             	mov    QWORD PTR [rbx],rax
  8d:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
  92:	48 89 43 08          	mov    QWORD PTR [rbx+0x8],rax
  96:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
  9b:	48 89 43 10          	mov    QWORD PTR [rbx+0x10],rax
  9f:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
  a4:	48 83 c4 20          	add    rsp,0x20
  a8:	48 89 43 18          	mov    QWORD PTR [rbx+0x18],rax
  ac:	48 8b 84 24 c8 00 00 	mov    rax,QWORD PTR [rsp+0xc8]
  b3:	00 
  b4:	64 48 33 04 25 28 00 	xor    rax,QWORD PTR fs:0x28
  bb:	00 00 
  bd:	75 0c                	jne    cb <lyra2zz_hash+0xcb>
  bf:	48 81 c4 d0 00 00 00 	add    rsp,0xd0
  c6:	5b                   	pop    rbx
  c7:	5d                   	pop    rbp
  c8:	41 5c                	pop    r12
  ca:	c3                   	ret    
  cb:	e8 00 00 00 00       	call   d0 <lyra2zz_hash+0xd0>
