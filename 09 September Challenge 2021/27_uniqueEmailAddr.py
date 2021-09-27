class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        def normalize(localName):
            parts = localName.split("+")
            return parts[0].replace(".", "")
        
        uniqueEmails = set()
        for email in emails:
            localName, domainName = email.split("@")
            uniqueEmails.add(normalize(localName) + "@" + domainName)
            
        return len(uniqueEmails)
