class Solution {
    func soupServings(_ n: Int) -> Double {
        if n == 0 { return 0.5 }
        let m = Int(ceil(Double(n) / 25.0))
        var dp = [Int: [Int: Double]]()

        func calculateDP(_ i: Int, _ j: Int) -> Double {
            if i <= 0 && j <= 0 { return 0.5 }
            if i <= 0 { return 1.0 }
            if j <= 0 { return 0.0 }
            if let innerDict = dp[i], let dpValue = innerDict[j] { return dpValue }

            let result = (calculateDP(i - 4, j) + calculateDP(i - 3, j - 1) +
                    calculateDP(i - 2, j - 2) + calculateDP(i - 1, j - 3)) / 4.0
            dp[i, default: [Int: Double]()][j] = result
            return result
        }
        for k in 1...m where calculateDP(k, k) > 1 - 1e-5 { return 1.0 }
        return calculateDP(m, m)
    }
}