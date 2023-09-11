def dfs(tickets, path, origin):
    path.append(origin)
    if not tickets:
        return True
    
    for i, ticket in enumerate(tickets):
        if ticket[0] == origin:
            restTickets = tickets[:i] + tickets[i+1:]
            destination = ticket[1]
            if dfs(restTickets, path, destination):
                return True
            path.pop()
    return False

def solution(tickets):
    tickets.sort()
    path = []
    dfs(tickets, path, 'ICN')
    return path