import Control.Applicative hiding ((<|>),many)
import Control.Monad
import Data.Set
import System.IO
import Text.ParserCombinators.Parsec
import Text.Printf

data DescTree = DT Double Feature deriving Show
data Feature = NoFeature | Feature String DescTree DescTree deriving Show
feature = do
  id <- many1 letter
  whitespace
  true <- desc
  false <- desc
  return (Feature id true false)

desc = do
  char '('
  whitespace
  weight <- double
  whitespace
  option <- feature <|> return NoFeature
  char ')'
  whitespace
  return (DT weight option)

whitespace = many (oneOf " \r\n")
double = do
  str <- many1 (oneOf ".0123456789")
  return (read str :: Double)

main :: IO ()
main = do
  ntests <- read <$> getLine :: IO Int
  forM_ [1..ntests] $ \test -> do
   printf "Case #%d:\n" test
   treelines <- read <$> getLine :: IO Int
   treetext <- join <$> replicateM treelines getLine
   case parse desc "stdin" treetext of
    Left err -> error (show err)
    Right d -> do
     -- print d
     animals <- read <$> getLine :: IO Int
     replicateM_ animals $ do
      feature <- (flip member . fromList . drop 2 . words) <$> getLine
      let prob (DT p f) = p*prob' f
          prob' NoFeature = 1
          prob' (Feature n t f) | feature n = prob t
                                | otherwise = prob f
      printf "%.7f\n" (prob d)
