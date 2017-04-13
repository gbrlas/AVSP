------------------------------ Templates begin ------------------------------
-- ##### Language extensions #####
{-# LANGUAGE PackageImports, ScopedTypeVariables #-}
{-# LANGUAGE ViewPatterns, PatternGuards, BangPatterns, TupleSections #-}
-- {-# OPTIONS_GHC -fglasgow-exts #-}
{-# OPTIONS_GHC -cpp #-}
{-# OPTIONS_GHC -O2 -fvia-C -optc-O3 #-}

-- ##### Import libraries #####
-- import System.Random
import Prelude ()
import Prelude.Plus
import "mtl" Control.Monad.Cont (ContT (..), callCC, lift, liftIO)
import Control.Monad.ST
-- import Control.DeepSeq
-- import Data.Bits
-- import Data.Ratio
import Data.Char
-- import Data.Maybe
import Data.Array
-- import Data.Array.Unboxed
-- import Data.Array.IO
import Data.Array.ST
-- import Data.IORef
import Data.STRef
-- import Data.Tree
-- import Data.MemoTrie (memo, memo2)
import Numeric (showIntAtBase)
import qualified Data.Set as Set
-- import qualified Data.Map as Map
-- import Data.Sequence (ViewR (..), ViewL (..), viewr, viewl)
import Foreign.Marshal.Utils (fromBool, toBool)
import Text.Parsec hiding (many, many1, (<|>), optional)
import Text.Printf
import System.Win32.Types (maybeNum, numToMaybe)
-- import Test.QuickCheck
-- import Test.QuickCheck.Arbitrary
-- import Test.QuickCheck.Gen (Gen (..))
-- import Test.QuickCheck.Property
-- import Test.QuickCheck.Instances.Char
-- import Test.QuickCheck.Instances.List
-- import Test.QuickCheck.Instances.Num
import Debug.Trace (trace, traceShow)

-- ##### Debug & Trace #####
#define _DEBUG

infixr 0 .$.
infixr 9 ...

#ifdef _DEBUG
(.$.) f x   = traceShow x $ f x
(...) f g x = let x' = g x in traceShow x' $ f x'
_TRACE  x   = traceShow x x 
_TRACEP x   = liftIO $ print x
#else
(.$.)       = ($)
(...)       = (.)
#define _TRACE(x)  x
#define _TRACEP(x)
#endif

(?) b x y  = if b then x else y                   ; infixr 1 ?
(??) x y b = (?) b x y                            ; infixr 1 ??

-- ##### Utils #####
ignore :: Monad m => a -> m ()
ignore = const (return ())

space'       = (>> putChar ' ')
endl'        = (>> putChar '\n')

readInt      = read :: String -> Int
readInteger  = read :: String -> Integer
readInts     = map readInt
readIntegers = map readInteger

-- ##### List #####
splitBy n = takeWhile (not . null) . map (take n) . iterate (drop n)

elim, sortR :: Ord a => [a] -> [a]
elim = map head . group . sort
sortR      = sortBy (flip compare)
sortByFst, sortBySnd :: (Ord a, Ord b) => [(a, b)] -> [(a, b)]
sortByFst  = sortBy (comparing fst)
sortBySnd  = sortBy (comparing snd)
groupByFst, groupBySnd :: (Eq a, Eq b) => [(a, b)] -> [[(a, b)]]
groupByFst = groupBy ((==) `on` fst)
groupBySnd = groupBy ((==) `on` snd)

-- ##### Array #####
array2D (y, x) = listArray ((0, 0), (y - 1, x - 1))

arrayToLists n a = splitBy n $ elems a
arrayToList  n a = concat $ arrayToLists n a

arrayST2D a = runST $ do
  let b@(lb, ub) = bounds a
  let r = range b
  ma <- thaw a     :: ST s (STArray s (Int, Int) Int)
--  mr <- newSTRef 0 :: ST s (STRef s Int)
  forM_ r $ \p@(y, x) -> do
  -- Do something here
    return ()
  --
  getElems ma

-- ##### Parser #####
type MyParser r a = ParsecT String () (ContT (Either ParseError r) IO) a

lexeme :: MyParser r a -> MyParser r a
lexeme p = p <* spaces <?> "lexeme"

betweenC :: Char -> Char -> MyParser r a -> MyParser r a
betweenC a b p = between (lexeme (char a)) (lexeme (char b)) (lexeme p) <?> "betweenC"

integer :: (Integral a, Read a) => MyParser r a
integer = read <$> lexeme (some digit) <?> "integer"

float :: (Floating a, Read a) => MyParser r a
float = read <$> lexeme float' <?> "float" where
  float' = (++) <$> some digit <*> option "" ((:) <$> char '.' <*> some digit)

word :: MyParser r String
word = lexeme (some alphaNum) <?> "word"

times :: MyParser r a -> MyParser r [a]
times p = integer >>= (`count` p)

parens :: MyParser r a -> MyParser r a
parens p = betweenC '(' ')' p <?> "parens"

braces :: MyParser r a -> MyParser r a
braces p = betweenC '[' ']' p <?> "braces"

-- ##### Resources #####
-- GHC:        "http://www.haskell.org/ghc/docs/6.12.2/html/libraries/"
-- Others:     "http://hackage.haskell.org/package/"
------------------------------- Templates end -------------------------------

main = do
--  let fileName = "./A-small-attempt1.in"
  let fileName = "./A-large.in"
  let runMyParser p = (`runContT` return) . runPT p () ""
  r <- readFile fileName >>= runMyParser (spaces *> myParser)
  case r of
    Left err -> print err
    _        -> return ()

problem = do
  [n, m] <- count 2 integer
  xss <- split <$> count n line
  yss <- split <$> count m line
  return (n, m, xss, yss)
  where
    line = lexeme (some (some alphaNum <|> string "/"))
    split = map (filter (/= "/")) 
  
myParser = do
  [n :: Integer] <- count 1 integer
  forM_ [1 .. n] $ \i -> do
    (n, m, xss, yss) <- problem
    liftIO $ printf "Case #%d: %d\n" i (solve n m xss yss)

conv = map (('/' :) . concat . intersperse "/") . tail . inits

mkSet xss = foldl' f Set.empty xss where
  f acc xs =  foldl' (flip Set.insert) acc ys where
    ys = conv xs

solve n m xss yss = let s' = foldr f s yss in Set.size s' - Set.size s where
  s = mkSet xss
  f zss acc = calc acc [] $ map ('/' :) zss where
    calc acc _   []   = acc
    calc acc as (bs:bss)
      | Set.member as' acc = calc acc as' bss
      | otherwise         = calc (Set.insert as' acc) as' bss where
        as' = as ++ bs
       
