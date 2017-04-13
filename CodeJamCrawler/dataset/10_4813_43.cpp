structure RollerCoaster =
struct
   exception NotImplemented
   exception InvariantViolated

   fun readFile name : {rides:int, rideMax:int, groups:int list} list = 
      let
         val inFile : TextIO.instream = TextIO.openIn name
         
         fun processLine1 (line : string) : (int * int) = 
            let
               val [ridesStr, rideMaxStr, _] = String.tokens 
                  (fn c => (String.str c) = " ") line
               val (SOME rides, SOME rideMax) = 
                  (Int.fromString ridesStr, Int.fromString rideMaxStr)
            in
               (rides, rideMax)
            end

         fun processLine2 (line : string) : int list = 
            let
               val groupsStr : string list = String.tokens 
                  (fn c => (String.str c) = " ") line
            in
               List.map (fn s => case Int.fromString s of 
                  (SOME n) => n | 
                  NONE => raise InvariantViolated) groupsStr
            end

         fun processFile () : {rides:int, rideMax:int, groups:int list} list =
            case (TextIO.inputLine inFile, TextIO.inputLine inFile) of
               (SOME line1, SOME line2) => 
                  let
                     val (rides, rideMax) = processLine1 line1
                     val groups : int list = processLine2 line2
                  in
                     {rides=rides, 
                     rideMax=rideMax, 
                     groups=groups} :: processFile ()
                  end
            |  (NONE, NONE) => []
               (* since there should be 2 * C lines, we should always 
                  have either 2 lines or 0 lines *)
            |  _ => raise InvariantViolated
      in
         (* get rid of the first line, then process the rest *)
         TextIO.inputLine inFile; processFile ()
      end

   fun runNumRides rides maxRide spaceLeft profit queue onRide accum = 
      if rides = 0 then
         profit
      else
         (case queue of 
            (x::xs) => 
               (* there's no space, so run the rollercoaster *)
               if spaceLeft < x then
                  runNumRides (rides-1) maxRide maxRide profit (x::xs) [] 
                     (onRide @ accum)
               else
                  runNumRides rides maxRide (spaceLeft-x) (profit+x) xs 
                     (x::onRide) accum
         |  [] => case accum of 
               (* if no one is in the accumulator, then just run the ride *)
               [] => runNumRides (rides-1) maxRide maxRide profit 
                  (List.rev onRide) [] []
               (* otherwise reverse it and put them back in the normal queue *)
            |  _ => runNumRides rides maxRide spaceLeft profit (List.rev accum) 
               onRide [])

   fun processInput ((v::vs) : {rides:int, rideMax:int, groups:int list} list) (caseNum : int) = 
      let
         val {rides, rideMax, groups} = v
         val profit : int = runNumRides rides rideMax rideMax 0 groups [] []
         val result = ("Case #" ^ (Int.toString caseNum) ^ ": " ^ 
            (Int.toString profit) ^ "\n")
      in
         result :: (processInput vs (caseNum+1))
      end
   |  processInput [] _ = [] 

   fun writeFile (name : string) (rs : string list) =
      let
         val outFile = TextIO.openOut name
         
         fun writeFileHelper (r::rs) = (TextIO.output (outFile, r);
            writeFileHelper rs)
         |  writeFileHelper [] = ()
      in
         writeFileHelper rs; TextIO.flushOut outFile
      end
end
