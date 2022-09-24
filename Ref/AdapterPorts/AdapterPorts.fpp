module Ref {

  @ Port for requesting an operation on two numbers
  port MessagePort(
                val: U32 @< The int to send/recieve
              )
}