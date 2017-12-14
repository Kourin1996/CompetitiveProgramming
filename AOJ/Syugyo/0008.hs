
main :: IO ()
main = do
    cs <- getContents
    putStr $ unlines $ map solve $ lines cs

solve :: String -> String
solve n = show $ length [ (a,b,c,d) | a<-[0..9], b<-[0..9], c<-[0..9], d<-[0..9], a+b+c+d == (read n) ]