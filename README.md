TESTANDO GPIOs E BOTÃO (STM32)
-------------------------------------
Resumo : Este artefato se trata de um projeto construído em cima de um microcontrolador STM32, especificamente a Franzininho C0 (STM32C011F6P6) com foco em *Desenvolvimento Orientado a Testes*.
Durante o projeto foram desenvolvidos testes inicias em C usando ferramentas como CPPUTest e CMake para controlar testes unitários a respeito das GPIOs e Leds do microcontrolador.

INICIANDO O PROJETO:
------------------------------------
Inicialmente o projeto foi criado a partir do STM32 Mx com foco nas GPIOs e seu acionamento, utilizando os leds B6 e B7 da Franzininho C0 juntamente com seu botão integrado na GPIO(A8).
Após determinar o foco principal do projeto foi criado novas pastas adicionais ao projeto antes mesmo de sua execução no STM32cubeIDE, das quais podemos ver a seguir:

ProjectLib/ Include /Utils...

ProjectLib/ Src/ ...

Tests/ Include/ Utils ...

Tests/Include / Src...

Dentro da pasta Utils foi criado o arquivo header led.h onde foi implementada a interface do projeto com funções básicas para testar um led em estado de SET(Ligado),
um led em estado de RESET(Desligado), led's em estado de Toggle(Alternando) e uma função de PushButtom(Para quando um botão for pressionado).
Inicialmente este documento abordará as funções mais básicas envolvendo leds e posteriomente falarei sobra a ultima função.

Dentro da pasta Tests foi criado também pastas similares que abrigam o coração de nossos testes, arquivos .cpp , um ponto importante aqui é de que como estamos lidando com arquivos .c
precisamos realizar um CASTING, uma conversão que nos possibilita executar um arquivo .cpp, a mesma pode ser vista a seguir: 

#ifdef __cplusplus

extern "C"{

#endif

[...]

#ifdef __cplusplus

}

#endif

Com poucas linhas de código foi possível executar o arquivo .cpp que nos possibilita realizar nossos testes.

CPPUTEST e CMAKE
----------------------------------
Antes de prosseguirmos mais adiante é preciso falar sobre nosso framework de testes, o CppUTest.
Uma ferramenta poderosa, com uma curva de aprendizado mais íngreme no início mas recompesadora, utilizando arquivos CMakeLists.txt no corpo principal do peojeto, 
dentro da pasta projectsLib e na pasta Tests foram construídas configurações essenciais para o compilamento do código no host (Sem uso do target), os quais podem ser vistos a seguir:

{

cmake_minimum_required(VERSION 3.22)

set(CMAKE_G_FLAGS -m32)
set(CMAKE_CXX_FLAGS -m32)

project(Led_Testes LANGUAGES C CXX)

add_subdirectory(projectLib)

add_subdirectory(Tests)

target_link_libraries(projectLib
)

}

{

cmake_minimum_required(VERSION 3.22)

add_library(projectLib OBJECT
 src/led.c
)

target_compile_definitions(projectLib PUBLIC STM32C011xx)

target_include_directories(projectLib
 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include

  ${CMAKE_SOURCE_DIR}/Core/Inc
  ${CMAKE_SOURCE_DIR}/Drivers/STM32C0xx_HAL_DRIVER/Inc
  ${CMAKE_SOURCE_DIR}/Drivers/STM32C0xx_HAL_DRIVER/Inc/Legacy
  ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/DEVICE/ST/STM32C0xx/Include
  ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/Include
)

}

{

cmake_minimum_required(VERSION 3.22)

add_executable(test_on_host
 src/main_test.cpp
 src/utils/ut_gpio.cpp
)

target_include_directories(test_on_host
 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(test_on_host
 projectLib
 CppUTest
 CppUTestExt
)

include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master
    SOURCE_DIR     "${CMAKE_SOURCE_DIR}/thirdy-party/cpputest"       
)
FetchContent_MakeAvailable(CppUTest)

 }

 Com poucas configurações foi possível construir um ambiente de testes que servem ao propósito desse documento. Um ponto a se observar são os includes no arquivo CMakeLists.txt da pasta projectLib,
 foi necessário adicionar todos esses caminhos para serem criados as funções mocks (funções que simulam o comportamento real do hardware (target) que estamos usando), como usamos o DEVICE STM32C011xx, 
 foi adicionado o target_compile_definitios(projectLib ${DEVICE}), sem essa linha de configuração se torna quase impossível simular uma função da lib HAL. O CppUTest foi carregado através de seu repósitoro.

 TESTES
 ---------------------------------
 Foram criados alguns testes básicos com implementações utilizando "printf" para validar o funcionamento de funções.
 As funções de mocks foram criadas para simular a leitura do estado de um pino, modificar o estado de um pino e integrar tais funções em uma função que utiliza o botão integrado da Franzinho C0.
 As funções criadas foram as seguintes seguinto o cabeçalho do arquivo.h

 Mocks :

 void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, GPIO_PinState state){}

 void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx. uint16_t GPIO_PIN){}

 GPIO_PinState HAL_GPIO_ReadPin(const GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN){
 
  [...]

 }

 As implementações dessas funções podem ser vistas no arquivo led.c

 RESULTADOS
 ---------------------------------
 Após validar os testes o código foi implementado no target e o funcionamento foi executado exatamente como esperado, ao pressionar o botão (A8), os leds irão mudar seu estado com base em um delay definido pelo usuário.

 Este projeto inicial tem como foco validar os conhecimentos no Desenvolvimento Orientado a testes.
 

 
