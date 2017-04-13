structure Snapper =
struct

   datatype snapper_state = On | Off

   exception NotImplemented

   fun readFile (name : string) : (int * int) list = 
      let
         (* open the input file for reading *)
         val inFile : TextIO.instream = TextIO.openIn name
         
         (* helper function to read in a line *)
         fun processLine (line : string) : (int * int) = 
            let
               val [nStr, kStr] : string list = String.tokens 
                  (fn c => (String.str c) = " ") line
            
               val (SOME n, SOME k) = (Int.fromString nStr, Int.fromString kStr)
            in
               (n, k)
            end
      
         (* read in each case *)
         fun output () : (int * int) list = 
            case TextIO.inputLine inFile of
               (SOME line) => (processLine line) :: output()
            |  NONE => []

      in
         TextIO.inputLine inFile; output ()
      end

   fun isLightOn ((n, k) : (int * int)) : bool = 
      let
         fun initSnappers (num : int) : snapper_state list = 
            if num = 0 then
               []
            else
               Off :: (initSnappers (num-1))

         val snappers : snapper_state list = initSnappers n
         
         fun snapFingers ((x::xs) : snapper_state list) power =
            (case x of
               Off => 
                  (* if we have power so far, then flip this one on and cont *)
                  if power then On :: (snapFingers xs false)
                  (* if we don't have power, then leave this one off *)
                  else Off :: xs
            |  On =>
                  (* if the power is on, turn this one off and the power for 
                     next nodes *) 
                  if power then Off :: (snapFingers xs true)
                  (* if the power is off, leave this one on *)
                  else On :: xs)
         |  snapFingers [] power = []
      
         fun snapKTimes snappers k = 
            if k = 0 then
               snappers
            else
               snapKTimes (snapFingers snappers true) (k-1)
         
         fun allOn ((x::xs) : snapper_state list) : bool = 
            (case x of
               On => allOn xs
            |  Off => false)
         |  allOn [] = true
      in
         allOn (snapKTimes snappers k)
      end

   fun processInput ((v::vs) : (int * int) list) (caseNum : int) = 
      let
         val on : bool = isLightOn v
         val result = ("Case #" ^ (Int.toString caseNum) ^ ": " ^ 
            (if on then "ON" else "OFF") ^ "\n")
      in
         result :: (processInput vs (caseNum+1))
      end
   |  processInput [] caseNum = []

   fun writeFile (rs : string list) = 
      let
         val outFile = TextIO.openOut "output.txt"
         
         fun writeFileHelper (r::rs) = (TextIO.output (outFile, r); 
            writeFileHelper rs)
         |  writeFileHelper [] = ()
      in
         writeFileHelper rs
      end
end
