import Control.Applicative

main :: IO ()
main = do
    cs <- getContents
    putStr $ unlines $ map show $ solve $ map read (lines cs)

solve :: [Int] -> [Int]
solve [] = []
solve (n':ns) = (solve' n'):(solve ns)
    where
        solve' :: Int -> Int
        solve' n = length $ takeWhile (\x -> x <= n) primes

primes = 2:3:[x|i<-[1..], j<-[-1,1], let x = 6*i+j, isPrime x]
    where
        isPrime n = null [i|i<-takeWhile (\x->x*x<=n) primes, rem n i == 0]