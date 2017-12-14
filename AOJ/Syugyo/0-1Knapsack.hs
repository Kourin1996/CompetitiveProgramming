import Control.Monad
import Control.Applicative

main :: IO ()
main = do
    [n,w] <- map read.words <$> getLine :: IO [Int]
    vwl <- map (map read.words).lines <$> getContents
    print vwl