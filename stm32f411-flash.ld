ENTRY(reset_handler())

MEMORY
{
  NAME(attr): ORIGIN = origin, LENGTH = len
  FLASH(rx): ORIGIN = 0x08000000, LENGTH = 512k
  SRAM(swx): ORIGIN = 0x20000000, LENGTH = 128k
}

SECTIONS
{
  /* Esta secao deve incluir a secao .text de todos os arquivos objeto de entrada *
  .text:
  {
  /* seção .isr_vectors do arquivo startup.o */
  KEEP(*(isr_vectors))
  . = ALIGN(4)
   /* combinar todas as secoes .text de todos arquivos de entrada */
  *(.text)
  ALIGN(4)
  /* Esta secao deve incluir a secao .rodata de todos arquivos objeto de entrada */
  *(.rodata)
  . = ALIGN(4)

  _la_data = .;
  }>FLASH

  .data:
  {
    /* combinar todas as secoes .data de todos arquivos objeto de entrada */
    _sdata = .;
    *(.data)
  . = ALIGN(4)
    _edata = .;
  }>SRAM AT> FLASH

  .bss:
  {
    /* combinar todas as sesoces .bss todos os arquivos de entrada */
    _sbss = .;     
    *(.bss)
    . = ALIGN(4)
    _ebss = .;
  }>SRAM AT> SRAM
}